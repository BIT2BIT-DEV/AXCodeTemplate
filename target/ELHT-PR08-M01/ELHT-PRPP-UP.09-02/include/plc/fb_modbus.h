/**
 * \file fb_modbus.h
 * \brief Функциональные блоки Modbus
 * \ingroup plc_com_modbus
 */

#pragma once

#include "fb_base.h"
#include "fb_serial_port.h"
#include "plc/fb_modbus_buffer.h"
#include "plc/fb_modbus_device.h"
#include "kernel/kernel_api_modbus.h"
#include "kernel/kernel_queues.h"


namespace plc
{
  /**
   * \addtogroup plc_com_modbus
   * \{
   */

  /**
   * \brief Список ошибок функциональных блоков Modbus
   * \details
   * Содержит список ошибок, характерных только для ФБ Modbus
   * \note Список ошибок с номером меньше 100 приведен в \ref FB_ERROR_CODE
   */
  enum MODBUS_ERROR_CODE
  {
    //! Неподдерживаемая функция, ошибка Modbus №1
    MODBUS_ERROR_CODE_ILLEGAL_FUNCTION      = 101,
    //! Неверный адрес регистров, ошибка Modbus №2
    MODBUS_ERROR_CODE_ILLEGAL_DATA_ADDRESS  = 102,
    //! Недопустымие значения регистров в запросе, ошибка Modbus №3
    MODBUS_ERROR_CODE_ILLEGAL_DATA_VALUE    = 103,
    //! Ошибка обработки данных на конечном устройстве, ошибка Modbus №4
    MODBUS_ERROR_CODE_SERVER_DEVICE_FAILURE = 104,
    //! Ошибка подготовки запроса Modbus Master
    MODBUS_ERROR_CODE_MASTER_REQUEST_ERROR  = 197,
    //! Получен неизвестный ответ
    MODBUS_ERROR_CODE_UNKNOWN_ANSWER        = 198,
    //! Устройство не отвечает
    MODBUS_ERROR_CODE_DEVICE_NOT_RESPONDING = 199
  };


  //! Пара значений адрес/значение регистра Modbus
  using modbus_register_pair_t = ETL_OR_STD::pair<uint16_t, modbus_register_t>;


  /**
   * \brief Функциональный блок Modbus Slave
   * \details
   * Используется для создания Modbus Slave RTU на указанном COM-порту.
   * Создание происходит при запуске программы, выполнение блока не требуется.
   * До выполнения блока используются настройки по умолчанию.
   * 
   * \note На одном порте может быть создано не более одной задачи,
   * использующей COM-порт.
   * 
   * Блок задает пользовательские таблицы регистров следующих типов:
   * - Holding Registers
   * - Input Registers
   * - Coils
   * - Discrete Inputs
   * 
   * Для задания таблиц регистров Holding Registers и Input Registers
   * используется класс \ref plc::ModbusBuffer<T>, где T - кол-во регистров,
   * для Coils и Discrete Inputs - \ref plc::ModbusCoilBuffer<T>,
   * где T - кол-во бит.
   * 
   * Задание таблиц происходит при создании ФБ через указатели на буферы
   * и не может быть изменено.
   * 
   * Для Holding Registers и Input Registers можно задавать один и тот же
   * буфер Modbus как в одном функциональном блоке Modbus Slave, так и в разных
   * (аналогично для Coils и Discrete Inputs). В таком случае таблица регистров
   * будет общей для всех использующих его Modbus Slave. 
   * 
   * При запуске ФБ копируются входные параметры блока и
   * передаются в Modbus Slave
   * 
   * Блок перейдет в состояние DONE если параметры будут применены в 
   * Modbus Slave.
   * 
   * Блок перейдет в состоние ERROR, если хотя бы один из входных параметров
   * имеет недопустимое значение, либо произошла критическая ошибка и сохранить
   * настройки не удалось.
   */
  class ModbusSlave : public ETrigATo, protected component_link
  {
  public:
    //! Номер COM-порта
    const COM com;
    //! Таблица Holding Registers
    iModbusBuffer* const holding_registers;
    //! Таблица Input Registers 
    iModbusBuffer* const input_registers;
    //! Таблица Coils
    iModbusCoilBuffer* const coils;
    //! Таблица Discrete Input
    iModbusCoilBuffer* const discrete_inputs;

    //! Адрес Slave в сети Modbus
    uint8_t address;
    //! Скорость обмена, бит/с
    uint32_t baudrate;
    //! Четность
    COM_PARITY parity;
    //! Кол-во стоп-битов 
    uint8_t stop_bits;
    //! Пауза перед отправкой ответа (мс)
    uint16_t poll_delay;

  protected:
    //! Структура инициализации ФБ Modbus Slave
    struct Init
    {
      //! Номер COM-порта
      const COM com;
      //! Таблица Holding Registers
      iModbusBuffer* const holding_registers {nullptr};
      //! Таблица Input Registers 
      iModbusBuffer* const input_registers {nullptr};
      //! Таблица Coils
      iModbusCoilBuffer* const coils {nullptr};
      //! Таблица Discrete Inputs
      iModbusCoilBuffer* const discrete_inputs {nullptr};

      //! Адрес Slave в сети Modbus
      uint8_t address {1};
      //! Скорость обмена, бит/с
      uint32_t baudrate {115200};
      //! Четность
      COM_PARITY parity {COM_PARITY_NONE};
      //! Кол-во стоп-битов 
      uint8_t stop_bits {1};
      //! Пауза перед отправкой ответа (мс)
      uint16_t poll_delay {0};
    };

  public:
    /**
     * \brief Конструктор Modbus Slave
     * \param init Структура инициализации входных параметров
     * \details
     * Структуру инициализации нужно поместить в фигурные скобки в аргументы
     * конструктора:
     * \code{.cpp}
     * ModbusSlave slave({
     *   .com = COM1,
     *   .holding_registers = &holding_buffer,
     *   .input_registers   = &input_buffer,
     *   .coils             = &coil_buffer,
     *   .discrete_inputs   = &discrete_buffer,
     *   .address   = 1,
     *   .baudrate  = 115200,
     *   .parity    = COM_PARITY_NONE,
     *   .stop_bits = 1
     * });
     * \endcode
     * 
     * Если в структуре инициализации не будет указан один из аргументов
     * (например, baudrate), то он примет значение по умолчанию из объявления
     * структуры Init.
     * 
     * Если таблица регистров не используется, в соответствующем аргументе
     * конструктора нужно указать "nullptr".
     * 
     * Параметры конструктора должны идти в порядке, указанном в объявлении
     * структуры инициализации Init.
     */
    ModbusSlave(const Init& init);

  private:
    inline static component_list<ModbusSlave> _list;
    TaskHandle_t _task;

    virtual FB_STATE processExecuting() override final;

    friend component_list<ModbusSlave>;
    friend class ComponentListHandler;
    friend class ModbusSlaveLastResponseTime;
  };


  /**
   * \brief Входные параметры функционального блока определения времени 
   * последнего обмена Modbus Slave с мастером \ref ModbusSlaveLastResponseTime
   */
  struct ModbusSlaveLastResponseTime_Input
  {
    //! Функциональный блок Modbus Slave
    ModbusSlave* slave{nullptr};
  };


  /**
   * \brief Определяет время последнего обмена Modbus Slave с мастером
   * \details
   * Обновляет время при выполнении блока
   */
  class ModbusSlaveLastResponseTime
  : public ETrig, public ModbusSlaveLastResponseTime_Input
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = ModbusSlaveLastResponseTime_Input;

    //! Время последнего обмена с мастером
    uint32_t time() { return _time; }

    ModbusSlaveLastResponseTime(const Input& init=Input{});
  
  private:
    uint32_t _time;
    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Список устройств для автоматического опроса в ФБ Modbus Master
   * \tparam N Максимальное кол-во устройств для опроса
   */
  template<size_t N>
  class ModbusMasterPoll : public etl::array<modbus::Device*, N>
  {
    using base_class = etl::array<modbus::Device*, N>;

  public:
    ModbusMasterPoll()
    : base_class{}
    {
    }

    template<typename... DEVICE_T>
    ModbusMasterPoll(DEVICE_T&... devices, ...)
    : base_class{&devices...}
    {
    }

    ModbusMasterPoll(std::initializer_list<modbus::Device*> devices)
    : base_class{devices}
    {
    }
  };

  template<typename... DEVICE_T>
  ModbusMasterPoll(DEVICE_T...) -> ModbusMasterPoll<sizeof...(DEVICE_T)>;


  /**
   * \brief Входные параметры функционального блока Modbus Master
   */
  struct ModbusMaster_Input
  {
    //! Номер COM-порта
    const COM com;
    //! Список устройств для автоматического опроса
    const etl::span<modbus::Device*> devices{};
    //! Скорость обмена, бит/с
    uint32_t baudrate {115200};
    //! Четность
    COM_PARITY parity {COM_PARITY_NONE};
    //! Кол-во стоп-битов
    uint8_t stop_bits {1};
    //! Пауза перед отправкой команды опроса (мс)
    uint16_t poll_delay {0};
    //! Пауза после отправки широковещательного запроса (мс)
    uint16_t turnaround_delay {100};
    //! Время ожидания ответа (мс)
    uint16_t response_timeout {300};
    //! Количество попыток связи
    uint16_t failed_attempts {3};
    //! Время возобновления опроса (мс)
    uint16_t restore_timeout {3000};
  };


  /**
   * \brief Функциональный блок Modbus Master
   * \details
   * Используется для создания Modbus Master RTU на указанном COM-порту.
   * Создание происходит при запуске программы, выполнение блока не требуется.
   * До выполнения блока используются настройки по умолчанию.
   * 
   * \note На одном порте может быть создано не более одной задачи,
   * использующей COM-порт.
   * 
   * Для отправки запросов Modbus к устройствам в сети используется
   * функциональный блок \ref ModbusMasterRequest.
   * 
   * Блок перейдет в состояние DONE если параметры будут применены в 
   * Modbus Master.
   * 
   * Блок перейдет в состоние ERROR, если хотя бы один из входных параметров
   * имеет недопустимое значение, либо произошла критическая ошибка и сохранить
   * настройки не удалось.
   * 
   * Входные параметры блока применяются ко всем отправляемым запросам Modbus:
   * - Параметр \ref poll_delay задает паузу между отправками посылок Modbus
   * - Параметр \ref response_timeout задает время ожидания ответа на посылку
   * - Параметр \ref failed_attempts задает количество попыток отправки
   * посылок, если не был получен верный ответ на запрос
   */
  class ModbusMaster : 
    public ModbusMaster_Input, public ETrigATo, protected component_link
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = ModbusMaster_Input;

    /**
     * \brief Конструктор Modbus Master
     * \param init Структура инициализации входных параметров
     * \details
     * Структуру инициализации нужно поместить в фигурные скобки в аргументы
     * конструктора:
     * \code{.cpp}
     * ModbusMaster modbus_master({
     *   .com        = COM1,
     *   .devices    = {}, // Или объект класса ModbusMasterPoll<N>
     *   .baudrate   = 115200,
     *   .parity     = COM_PARITY_NONE,
     *   .stop_bits  = 1,
     *   .poll_delay = 0,
     *   .turnaround_delay = 100,
     *   .response_timeout = 300,
     *   .failed_attempts  = 3,
     *   .restore_timeout  = 3000
     * });
     * \endcode
     * 
     * Если в структуре инициализации не будет указан один из аргументов
     * (например, baudrate), то он примет значение по умолчанию из объявления
     * структуры входных параметров \ref ModbusMaster_Input.
     * 
     * Если автоматический опрос не используется, в аргументе .devices
     * нужно указать "{}".
     * 
     * Параметры конструктора должны идти в порядке, указанном в объявлении
     * структуры входных параметров \ref ModbusMaster_Input.
     */
    ModbusMaster(const Input& init);

  private:
    inline static component_list<ModbusMaster> _list;
    TaskHandle_t _task;

    virtual FB_STATE processExecuting() override final;

    friend component_list<ModbusMaster>;
    friend class ComponentListHandler;
    friend class __ModbusMasterRequest;
  };


  /**
   * \brief Интерфейсный блок запросов Modbus Master
   * \details
   * Используется для создания функциональных блоков отправки запросов
   * к Modbus Master.
   * 
   */
  class __ModbusMasterRequest : public ETrig
  {  
  protected:
    ModbusMaster* _master;
    kernel::tasks_modbus::Request _request;

    kernel::QueueMemory<kernel::tasks_modbus::Request, 1>
      _request_response_memory;
    kernel::Queue<kernel::tasks_modbus::Request> _request_response;

    __ModbusMasterRequest();

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока запросов Modbus Master
   */
  struct ModbusMasterRequest_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master {nullptr};
    //! Адрес опрашиваемого устройства
    uint8_t  device_address {1};
    //! Номер функции Modbus
    uint8_t  function {3};
    //! Начальный адрес регистров Modbus в запросе
    uint16_t starting_address {0};
    //! Указатель на таблицу регистров
    iModbusBufferBase* buffer {nullptr};
    //! Общее кол-во регистров Modbus
    uint16_t registers_count {0};
    //! Максимальное кол-во регистров Modbus в одном запросе к устройству
    uint16_t device_max_registers {0};
    //! Время ожидания ответа в запросе, мс (0 - настройки из Modbus Master)
    uint16_t response_timeout {0};
  };


  /**
   * \brief Функциональный блок запросов Modbus Master
   * \details
   * Используется для отправки запросов к устройствам Modbus Slave RTU в сети.
   * 
   * Выполнение блока подготавливает и отправляет в сеть посылку Modbus с 
   * входными параметрами блока. Если с указанными параметрами нельзя выполнить
   * запрос за одну посылку Modbus, блок автоматически сформирует и отправит
   * новые запросы в сеть Modbus.
   * 
   * В случае ошибки связи блок повторит попытку связи несколько раз, если
   * задано соответствующее значение параметра в Modbus Master (всего будет
   * сделано \ref ModbusMaster::failed_attempts попыток). Ошибками связи
   * считаются:
   * - Slave-устройство вернет одну из стандартных ошибок MODBUS (от 1 до 12)
   * - Slave-устройство вернет неизвестный ответ
   * - Slave-устройство не ответит за время \ref ModbusMaster::response_timeout
   * 
   * Блок перейдет в состояние DONE, если на все запросы был получен требуемый
   * ответ.
   * 
   * Блок перейдет в состояние ERROR, если за несколько попыток выполнения
   * ни разу не придет верный ответ.
   * 
   * Блок имеет следующие входные параметры:
   * - Адрес устройства \ref device_address может быть от 0 до 247. Указание
   * адреса 0 отправляет широковещательный запрос.
   * - В \ref function записывается номер функции Modbus
   * - В \ref starting_address записывается адрес первого регистра Modbus
   * - В \ref buffer записывается указатель на буфер регистров Modbus
   * - В \ref registers_count записывается общее количество регистров Modbus:
   *   - При значении 0 будет заполнен весь буфер регистров \ref buffer
   *   - При значении от 1 до размера буфера регистров \ref buffer будет
   *   считано указанное кол-во регистров
   *   - При значении больше размера буфера регистров ФБ вернет ошибку
   * - В \ref device_max_registers записывается максимальное кол-во регистров
   * в посылке Modbus, которое может обработать опрашиваемое устройство. При
   * значении 0 кол-во регистров берется по стандарту Modbus.
   * - В \ref response_timeout может быть записано время (мс), в течение
   * которого нужно нужно ждать ответ от устройства на текущий запрос. Если
   * параметр равен нулю, Modbus Master будет использовать собственное значение
   * параметра response_timeout. Для широковещательных посылок и функций,
   * не требующих ответа, параметр задает время паузы после отправки посылки.
   * В таком случае при значении 0 Modbus Master использует собственное значение
   * параметра turnaround_delay
   */
  class ModbusMasterRequest :
    public ModbusMasterRequest_Input, public __ModbusMasterRequest
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = ModbusMasterRequest_Input;

    /**
     * \brief Общее кол-во регистров в последнем выполненном запросе ФБ
     * \details
     * Параметр имеет верное значение только в состояниях DONE или ERROR
     */
    uint16_t count() const { return _registers_count; }

    /**
     * \brief Время начала обработки запроса в Modbus Master
     * \details
     * Соответствует времени, когда до текущего запроса дошла очередь в Modbus
     * Master.  
     * Параметр имеет верное значение только в состояниях DONE или ERROR
     */
    uint32_t send_time() const { return _request.request.send_time; }

  public:
    /**
     * \brief Конструктор функционального блока запроса Modbus Master
     * \param init Структура инициализации входных параметров
     * \details
     * Структуру инициализации нужно поместить в фигурные скобки в аргументы
     * конструктора:
     * \code{.cpp}
     * ModbusMasterRequest master_request({
     *   .master           = &modbus_master,
     *   .device_address   = 1,
     *   .function         = 3,
     *   .starting_address = 0,
     *   .buffer           = &request_buffer,
     *   .registers_count  = 0,
     *   .device_max_registers = 0,
     *   .response_timeout = 0
     * });
     * \endcode
     * 
     * Если в структуре инициализации не будет указан один из аргументов
     * (например, function), то он примет значение по умолчанию из объявления
     * структуры Input.
     * 
     * При инициализации допускается не указывать аргументы master и buffer, но
     * в таком случае они должны быть обязательно записаны до выполнения ФБ.
     * 
     * Параметры конструктора должны идти в порядке, указанном в объявлении
     * структуры входных параметров Input.
     */
    ModbusMasterRequest(const Input& init={});

  private:
    ModbusFBDevice _device;
    uint16_t _registers_count;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока записи списка регистров
   * по одному
   * \details
   * Используется в \ref ModbusMasterWriteSingleRegistersList
   */
  struct ModbusMasterWriteSingleRegistersList_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Адрес записываемого устройства
    uint8_t       device_address{1};
    //! Функция записи
    uint8_t       function{6};
    //! Список значений "адрес регистра/значение регистра" для записи
    etl::ivector<modbus_register_pair_t>* list{nullptr};
    //! Время ожидания ответа в запросе, мс (0 - настройки из Modbus Master)
    uint16_t      response_timeout{0};
  };


  /**
   * \brief Функциональный блок записи списка регистров по одному
   * \details
   * Блок используется в случае, когда записываемые регистры идут не подряд,
   * и промежуточные регистры между ними не должны изменяться.
   * 
   * Допустимые функции Modbus для записи:
   * - 6  (Write Single Register)
   * - 16 (Write Multiple Registers)
   * 
   * При выборе функций записи нескольких регистров функциональный блок все еще
   * будет записывать регистры по одному.
   * 
   * Порядок записи - с первого элемента в списке list по последний. Список
   * не должен изменяться пока работает функциональный блок.
   */
  class ModbusMasterWriteSingleRegistersList
  : public ModbusMasterWriteSingleRegistersList_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = ModbusMasterWriteSingleRegistersList_Input;

    /**
     * \brief Кол-во записанных регистров
     * \details
     * Может использоваться в состоянии ERROR для анализа причин ошибки.
     * 
     * В состоянии DONE кол-во регистров всегда соответствует размеру списка
     */
    size_t writed_registers() const;

    /**
     * \brief Время начала обработки запроса в Modbus Master
     * \details
     * Соответствует времени, когда до текущего запроса дошла очередь в Modbus
     * Master.   
     * Параметр имеет верное значение только в состояниях DONE или ERROR
     */
    uint32_t send_time() const;

    /**
     * \brief Конструктор функционального блока
     * \param init Входные параметры
     */
    ModbusMasterWriteSingleRegistersList(const Input& init=Input{});

  protected:
    ModbusMasterRequest _request;
    ModbusBuffer<1>     _buffer;
    etl::ivector<modbus_register_pair_t>* _list;
    size_t              _list_index;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока чтения списка регистров
   * по одному
   * \details
   * Используется в \ref ModbusMasterReadSingleRegistersList
   */
  struct ModbusMasterReadSingleRegistersList_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster*       master{nullptr};
    //! Адрес опрашиваемого устройства
    uint8_t             device_address{1};
    //! Функция чтения (определяет область регистров Modbus)
    uint8_t             function{4};
    //! Список значений "адрес регистра/значение регистра" для чтения
    etl::ivector<modbus_register_pair_t>* list{nullptr};
    //! Время ожидания ответа в запросе, мс (0 - настройки из Modbus Master)
    uint16_t      response_timeout{0};
  };


  /**
   * \brief Функциональный блок чтения списка регистров по одному
   * \details
   * Блок используется в случае, когда выгоднее прочитать требуемые регистры 
   * по одному, без промежуточных регистров.
   * 
   * Область памяти регистров, из которой происходит чтение, определяется
   * по номеру функции:
   * - 3 функция читает из области Holding Registers
   * - 4 функция читает из области Input Registers
   * 
   * Регистры читаются по списку, начиная с первого.
   */
  class ModbusMasterReadSingleRegistersList :
    public ModbusMasterReadSingleRegistersList_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = ModbusMasterReadSingleRegistersList_Input;

    /**
     * \brief Указатель на прочитанный список регистров
     * \details
     * Параметр гарантированно имеет верное значение только в состоянии DONE
     * или ERROR
     * 
     * \retval nullptr Если блок никогда не выполнялся
     */
    etl::ivector<modbus_register_pair_t>* readed_list();

    /**
     * \brief Кол-во прочитанных регистров
     * \details
     * Показывает сколько регистров в \ref readed_list() имеют верное значение.
     * 
     * Параметр может использоваться в состоянии ERROR для определения
     * ошибочного регистра
     */
    size_t readed_registers();

    /**
     * \brief Время начала обработки запроса в Modbus Master
     * \details
     * Соответствует времени, когда до текущего запроса дошла очередь в Modbus
     * Master.   
     * Параметр имеет верное значение только в состояниях DONE или ERROR
     */
    uint32_t send_time() const;

    /**
     * \brief Конструктор функционального блока
     * \param init Входные параметры
     */
    ModbusMasterReadSingleRegistersList(const Input& init=Input{});

  protected:
    ModbusMasterRequest _request;
    ModbusBuffer<1>     _buffer;
    etl::ivector<modbus_register_pair_t>* _list;
    size_t              _list_index;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока настройки таблицы параметров
   * в устройстве Modbus
   */
  struct ModbusMasterParameterSetup_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Устройство (должно быть nullptr если не используется)
    modbus::Device* device{nullptr};
    //! Адрес устройства в сети Modbus (используется если не указано устройство)
    uint16_t device_address{1};
    //! Таблица параметров
    menu::iTable* table{nullptr};
    //! Адрес первого регистра таблицы параметров в устройстве
    uint16_t table_address{0};
    //! Флаг чтения настроек в таблицу параметров
    bool read{false};
    //! Функция чтения из таблицы параметров
    uint8_t read_function{0x03};
    //! Функция записи в таблицу параметров
    uint8_t write_function{0x10};
    //! Время ожидания ответа в запросе, мс (0 - настройки из Modbus Master)
    uint16_t response_timeout{0};
  };


  /**
   * \brief Функциональный блок настройки таблицы параметров в устройстве
   * Modbus
   * \details
   * Блок позволять считывать и записывать таблицы параметров по Modbus.
   * 
   * Блок поддерживает задание адреса двумя способами:
   * - Автоопределение адреса через указатель на устройство device. В таком
   * случае входной параметр device_address игнорируется
   * - Ручная установка адреса через параметр device_address. В таком случае
   * указатель device должен быть равен nullptr
   */
  class ModbusMasterParameterSetup :
    public ModbusMasterParameterSetup_Input, public __ModbusMasterRequest
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = ModbusMasterParameterSetup_Input;

    /**
     * \brief Флаг считывания таблицы параметров при последнем выполнении блока
     * \details
     * Параметр имеет верное значение только в состояниях DONE или ERROR
     */
    bool readed() const;

    ModbusMasterParameterSetup(const Input& init=Input{});

  protected:
    menu::iTable* _table;
    menu::TableNode<1> _node;
    modbus::ModbusTree<1> _tree;
    modbus::ModbusPollChannel _poll_channel;

    virtual FB_STATE processExecuting() override;
  };

  /**
   * \}
   * \noop plc_com_modbus
   */
}
