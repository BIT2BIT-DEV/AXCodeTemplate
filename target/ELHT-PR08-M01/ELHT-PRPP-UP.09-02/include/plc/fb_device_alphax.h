/**
 * \file plc/fb_device_alphax.h
 * \brief Модули расширения Alpha-X
 */

#pragma once

#include "plc/fb_modbus.h"
#include "modbus/devices/elhart/alphax_module.h"
#include "modbus/devices/elhart/alphax_di.h"
#include "modbus/devices/elhart/alphax_do.h"
#include "modbus/devices/elhart/alphax_dio.h"
#include "modbus/devices/elhart/alphax_ai.h"

namespace plc
{
  namespace alphax_parameter = modbus::devices::elhart::alphax_parameter;
  using AlphaXDevice = modbus::devices::elhart::AlphaXDevice;
  using AlphaXModule = modbus::devices::elhart::AlphaXModule;
  using AlphaX_DI    = modbus::devices::elhart::AlphaX_DI;
  using AlphaX_DO    = modbus::devices::elhart::AlphaX_DO;
  using AlphaX_DIO   = modbus::devices::elhart::AlphaX_DIO;
  using AlphaX_AI    = modbus::devices::elhart::AlphaX_AI;

  /**
   * \brief Список модулей расширения Alpha-X для опроса в Modbus Master
   */
  template<size_t N>
  class AlphaXModulePoll : public plc::ModbusMasterPoll<N>
  {
    using base_class = plc::ModbusMasterPoll<N>;

  public:
    /**
     * \brief Конструктор списка модулей расширения
     * \param address Адреса Modbus модулей расширения
     */
    template<typename... ADDR>
    AlphaXModulePoll(ADDR... address, ...)
    : base_class{},
      modules{AlphaXModule(address)...}
    {
      for(size_t i = 0; i < N; ++i)
      {
        base_class::operator[](i) = &modules[i];
      }
    }

    etl::array<AlphaXModule, N> modules;
  };

  template<typename... ADDR>
  AlphaXModulePoll(ADDR...) -> AlphaXModulePoll<sizeof...(ADDR)>;

  /**
   * \brief Входные параметры функционального блока настройки дискретных
   * входов модуля Alpha-X
   * \details
   * Относится к ФБ \ref AlphaXModule_DiscreteInputSetup
   */
  struct AlphaXModule_DiscreteInputSetup_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Настраиваемое устройство
    AlphaXDevice* device{nullptr};
    //! Номер настраиваемого канала
    uint8_t channel{AlphaXModule::DINPUT_CHANNEL1};

    //! Записывать задержку включения (TON) DI
    bool write_ton{true};
    //! Записывать задержку выключения (TOF) DI
    bool write_tof{true};

    /**
     * \brief Задержка включения (TON) DI, x * 500 мкс
     * \details
     * Возможные значения: 0...50000
     */
    uint16_t ton{20};

    /**
     * \brief Задержка выключения (TOF) DI, x * 500 мкс
     * \details
     * Возможные значения: 0...50000
     */
    uint16_t tof{20};
  };

  /**
   * \brief Функциональный блок настройки дискретных входов модулей Alpha-X
   * \details
   * Работает только с модулями Alpha-X. Адрес модуля в сети Modbus берет 
   * из первого канала опроса.
   * 
   * Настраивает:
   * - Таймеры задержки включения и выключения
   * 
   * Не настраивает:
   * - НО/НЗ-контакты дискретного входа
   */
  class AlphaXModule_DiscreteInputSetup
  : public AlphaXModule_DiscreteInputSetup_Input, public ETrig
  {
  public:
    //! Структура входных параметров дискретного блока
    using Input = AlphaXModule_DiscreteInputSetup_Input;

    AlphaXModule_DiscreteInputSetup(const Input& input=Input{});

  protected:
    ModbusMasterWriteSingleRegistersList _request;
    AlphaXDevice* _device;
    etl::vector<modbus_register_pair_t, 2> _write_values;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока чтения настроек дискретных
   * входов модуля Alpha-X
   * \details
   * Относится к ФБ \ref AlphaXModule_DiscreteInputReadSettings
   */
  struct AlphaXModule_DiscreteInputReadSettings_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Считываемое устройство
    AlphaXDevice* device{nullptr};
    //! Номер считываемого канала
    uint8_t channel{AlphaXModule::DINPUT_CHANNEL1};

    //! Считать задержку включения (TON) DI
    bool read_ton{true};
    //! Считать задержку выключения (TOF) DI
    bool read_tof{true};
  };

  /**
   * \brief Функциональный блок чтения настроек дискретных входов
   * модулей Alpha-X
   * \details
   * Работает только с модулями Alpha-X. Адрес модуля в сети Modbus берет 
   * из первого канала опроса.
   * 
   * Считывает:
   * - Таймеры задержки включения и выключения
   * 
   * Не считывает:
   * - НО/НЗ-контакты дискретного входа
   */
  class AlphaXModule_DiscreteInputReadSettings
  : public AlphaXModule_DiscreteInputReadSettings_Input, public ETrig
  {
  public:
    //! Структура входных параметров дискретного блока
    using Input = AlphaXModule_DiscreteInputReadSettings_Input;

    /**
     * \brief Задержка включения (TON) DI, x * 500 мкс
     */
    uint16_t ton() const;

    /**
     * \brief Задержка выключения (TOF) DI, x * 500 мкс
     */
    uint16_t tof() const;


    /**
     * \brief Конструктор функционального блока
     * \param init Входные параметры
     */
    AlphaXModule_DiscreteInputReadSettings(const Input& init=Input{});

  protected:
    ModbusMasterReadSingleRegistersList _request;
    AlphaXDevice* _device;
    uint8_t _channel;
    etl::vector<modbus_register_pair_t, 2> _read_values;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока настройки дискретных
   * выходов модулей Alpha-X
   * \details
   * Относится к ФБ \ref AlphaXModule_DiscreteOutputSetup
   */
  struct AlphaXModule_DiscreteOutputSetup_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Настраиваемое устройство
    AlphaXDevice* device{nullptr};
    //! Номер настраиваемого канала
    uint8_t channel{AlphaXModule::DOUTPUT_CHANNEL1};

    //! Записывать период ШИМ выхода
    bool write_pwm_period{true};
    //! Записывать скважность ШИМ выхода
    bool write_pwm_duty_cycle{true};
    //! Записывать задержку включения (TON) выхода
    bool write_ton{true};
    //! Записывать задержку выключения (TOF) выхода
    bool write_tof{true};

    /**
     * \brief Период ШИМ, x * 100 мс
     * \details
     * Возможные значения:
     * - Для транзисторных выходов: 0...10000
     * - Для релейных выходов: 10...10000
     */
    uint16_t pwm_period{0};

    /**
     * \brief Скважность ШИМ выхода, % * 100
     * \details
     * Возможные значения: 0...10000
     */
    uint16_t pwm_duty_cycle{0};

    /**
     * \brief Задержка включения (TON) выхода, x * 1 с
     * \details
     * Возможные значения: 0...1000
     */
    uint16_t ton{0};

    /**
     * \brief Задержка выключения (TOF) выхода, x * 1 с
     * \details
     * Возможные значения: 0...1000
     */
    uint16_t tof{0};
  };


  /**
   * \brief Функциональный блок настройки дискретных выходов модулей Alpha-X
   * \details
   * Настраивает:
   * - Период ШИМ и скважность
   * - Задержки включения и выключения
   * 
   * Не настраивает:
   * - Безопасное состояние выхода
   */
  class AlphaXModule_DiscreteOutputSetup
  : public AlphaXModule_DiscreteOutputSetup_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = AlphaXModule_DiscreteOutputSetup_Input;

    /**
     * \brief Конструктор фунционального блока
     * \param init Входные параметры
     */
    AlphaXModule_DiscreteOutputSetup(const Input& init=Input{});

  protected:
    ModbusMasterWriteSingleRegistersList _request;
    etl::vector<modbus_register_pair_t, 4> _write_values;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока чтения настроек дискретных
   * выходов модулей Alpha-X
   * \details
   * Относится к ФБ \ref AlphaXModule_DiscreteOutputReadSettings
   */
  struct AlphaXModule_DiscreteOutputReadSettings_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Считываемое устройство
    AlphaXDevice* device{nullptr};
    //! Номер считываемого канала
    uint8_t channel{AlphaXModule::DOUTPUT_CHANNEL1};

    //! Считать период ШИМ выхода
    bool read_pwm_period{true};
    //! Считать скважность ШИМ выхода
    bool read_pwm_duty_cycle{true};
    //! Считать задержку включения (TON) выхода
    bool read_ton{true};
    //! Считать задержку выключения (TOF) выхода
    bool read_tof{true};
  };


  /**
   * \brief Функциональный блок чтения настроек дискретных выходов
   * модулей Alpha-X
   * \details
   * Считывает:
   * - Период ШИМ и скважность
   * - Задержки включения и выключения
   * 
   * Не считывает:
   * - Безопасное состояние выхода
   */
  class AlphaXModule_DiscreteOutputReadSettings
  : public AlphaXModule_DiscreteOutputReadSettings_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = AlphaXModule_DiscreteOutputReadSettings_Input;

    /**
     * \brief Период ШИМ, x * 100 мс
     */
    uint16_t pwm_period() const;

    /** 
     * \brief Скважность ШИМ выхода, % * 100
     */
    uint16_t pwm_duty_cycle() const;

    /**
     * \brief Задержка включения (TON) выхода, x * 1 с
     */
    uint16_t ton() const;

    /**
     * \brief Задержка выключения (TOF) выхода, x * 1 с
     */
    uint16_t tof() const;

    /**
     * \brief Конструктор фунционального блока
     * \param init Входные параметры
     */
    AlphaXModule_DiscreteOutputReadSettings(const Input& init=Input{});

  protected:
    ModbusMasterReadSingleRegistersList _request;
    uint8_t _channel;
    etl::vector<modbus_register_pair_t, 4> _read_values;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока настройки аналоговых
   * входов модуля Alpha-X
   * \details
   * Относится к ФБ \ref AlphaXModule_AnalogInputSetup
   */
  struct AlphaXModule_AnalogInputSetup_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Настраиваемое устройство
    AlphaXDevice* device{nullptr};
    //! Номер настраиваемого канала
    uint8_t channel{AlphaXModule::AINPUT_CHANNEL1};

    //! Записывать тип датчика
    bool write_type{true};
    //! Записывать степень фильтрации сигнала
    bool write_filter{true};
    //! Записывать нижнее значение для приведения к пользовательской шкале
    bool write_normalize_low{true};
    //! Записывать верхнее значение для приведения к пользовательской шкале
    bool write_normalize_high{true};
    //! Записывать нижний уровень аналогового сигнала
    bool write_level_low{true};
    //! Записывать верхний уровень аналогового сигнала
    bool write_level_high{true};
    //! Записывать нижнее аварийное значение сигнала
    bool write_alarm_low{true};
    //! Записывать верхнее аварийное значение сигнала
    bool write_alarm_high{true};
    //! Записывать наклон характеристики измерительного входа
    bool write_slope{true};
    //! Записывать сдвиг характеристики измерительного входа
    bool write_shift{true};
    //! Записывать положение десятичной точки аналогового входа
    bool write_decimal{true};
    //! Записывать отключение режекторного фильтра
    bool write_disable_notch_filter{true};
    //! Записывать компенсацию температуры холодного спая
    bool write_junction{true};

    /**
     * \brief Тип подключаемого датчика
     * \details
     * Возможные значения приведены в перечислении
     * \ref alphax_parameter::AINPUT_TYPE::VALUE.
     * 
     * Возможные значения отличаются для температурных и унифицированных 
     * аналоговых входов:
     * - Для температурных:   от 0 до 28 из перечисления выше, а также 42
     * - Для унифицированных: от 33 до 42 из перечисления выше
     * 
     * Значения по умолчанию:
     * - для температурных аналоговых входов   - 6  (Pt100, α = 0,00385 °С-1)
     * - Для унифицированных аналоговых входов - 36 (0... 10 В)
     */
    alphax_parameter::AINPUT_TYPE::VALUE type;

    /**
     * \brief Степень фильтрации сигнала
     * \details
     * Возможные значения: 0...8
     */
    uint16_t filter{2};

    /**
     * \brief Нижнее значение для приведения к пользовательской шкале (ед. изм.)
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t normalize_low{0};

    /**
     * \brief Верхнее значение для приведения к пользовательской шкале
     * (ед. изм.)
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t normalize_high{10000};

    /**
     * \brief Коррекция нижнего уровня аналогового сигнала
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t level_low{0};

    /**
     * \brief Коррекция верхнего уровня аналогового сигнала
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t level_high{10000};

    /**
     * \brief Нижнее аварийное значение сигнала в пользовательском диапазоне,
     * (ед. изм.)
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t alarm_low{0};

    /**
     * \brief Верхнее аварийное значение сигнала в пользовательском диапазоне,
     * (ед. изм.)
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t alarm_high{10000};

    /**
     * \brief Наклон характеристики измерительного входа
     * \details
     * Возможные значения: -32768...32767
     * - 0 - 0%
     * - 1000 - 100%
     */
    int16_t slope{1000};

    /**
     * \brief Сдвиг характеристики измерительного входа, (ед. изм.)
     * \details
     * Возможные значения: -32768....32767
     */
    int16_t shift{0};

    /**
     * \brief Положение десятичной точки аналогового входа
     * \details
     * Возможные значения: 0...3
     * 
     * Значения по умолчанию:
     * - Для унифицированных аналоговых входов: 2
     * - Для температурных аналоговых входов: 1
     */
    uint16_t decimal{2};

    /**
     * \brief Отключение режекторного фильтра
     * \details
     * Возможные значения:
     * - 0 (false) - Фильтр включен
     * - 1 (true)  - Фильтр отключен
     */
    bool disable_notch_filter{false};

    /**
     * \brief Компенсация температуры холодного спая
     * \details:
     * Возможные значения приведены в перечислении 
     * \ref alphax_parameter::AINPUT_JUNCTION::VALUE
     */
    alphax_parameter::AINPUT_JUNCTION::VALUE junction{
      alphax_parameter::AINPUT_JUNCTION::INTERNAL
    };
  };


  /**
   * \brief Функциональный блок настройки аналоговых входов модулей Alpha-X
   * \details
   * Работает только с модулями Alpha-X. Адрес модуля в сети Modbus берет 
   * из первого канала опроса.
   */
  class AlphaXModule_AnalogInputSetup : 
    public AlphaXModule_AnalogInputSetup_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = AlphaXModule_AnalogInputSetup_Input;

    /**
     * \brief Конструктор функционального блока
     * \param init Входные параметры
     */
    AlphaXModule_AnalogInputSetup(const Input& init=Input{});

  private:
    ModbusMasterWriteSingleRegistersList _request;
    etl::vector<modbus_register_pair_t, 13> _write_values;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока чтения настроек аналоговых
   * входов модуля Alpha-X
   * \details
   * Относится к ФБ \ref AlphaXModule_AnalogInputReadSettings
   */
  struct AlphaXModule_AnalogInputReadSettings_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Считываемое устройство
    AlphaXDevice* device{nullptr};
    //! Номер считываемого канала
    uint8_t channel{AlphaXModule::AINPUT_CHANNEL1};

    //! Считать тип датчика
    bool read_type{true};
    //! Считать степень фильтрации сигнала
    bool read_filter{true};
    //! Считать нижнее значение для приведения к пользовательской шкале
    bool read_normalize_low{true};
    //! Считать верхнее значение для приведения к пользовательской шкале
    bool read_normalize_high{true};
    //! Считать нижний уровень аналогового сигнала
    bool read_level_low{true};
    //! Считать верхний уровень аналогового сигнала
    bool read_level_high{true};
    //! Считать нижнее аварийное значение сигнала
    bool read_alarm_low{true};
    //! Считать верхнее аварийное значение сигнала
    bool read_alarm_high{true};
    //! Считать наклон характеристики измерительного входа
    bool read_slope{true};
    //! Считать сдвиг характеристики измерительного входа
    bool read_shift{true};
    //! Считать положение десятичной точки аналогового входа
    bool read_decimal{true};
    //! Считать отключение режекторного фильтра
    bool read_disable_notch_filter{true};
    //! Считать компенсацию температуры холодного спая
    bool read_junction{true};
  };


  /**
   * \brief Функциональный блок чтения настроек аналоговых входов
   * модулей Alpha-X
   * \details
   * Работает только с модулями Alpha-X. Адрес модуля в сети Modbus берет 
   * из первого канала опроса.
   */
  class AlphaXModule_AnalogInputReadSettings : 
    public AlphaXModule_AnalogInputReadSettings_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = AlphaXModule_AnalogInputReadSettings_Input;

    /**
     * \brief Тип подключаемого датчика
     * \details
     * Возможные значения приведены в перечислении
     * \ref alphax_parameter::AINPUT_TYPE::VALUE
     * 
     * Возможные значения отличаются для температурных и унифицированных 
     * аналоговых входов:
     * - Для температурных:   от 0 до 28 из перечисления выше, а также 42
     * - Для унифицированных: от 33 до 42 из перечисления выше
     * 
     * Значения по умолчанию:
     * - для температурных аналоговых входов   - 6  (Pt100, α = 0,00385 °С-1)
     * - Для унифицированных аналоговых входов - 36 (0... 10 В)
     */
    alphax_parameter::AINPUT_TYPE::VALUE type() const;

    /**
     * \brief Степень фильтрации сигнала
     * \details
     * Возможные значения: 0...8
     */
    uint16_t filter() const;

    /**
     * \brief Нижнее значение для приведения к пользовательской шкале (ед. изм.)
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t normalize_low() const;

    /**
     * \brief Верхнее значение для приведения к пользовательской шкале
     * (ед. изм.)
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t normalize_high() const;

    /**
     * \brief Коррекция нижнего уровня аналогового сигнала
     * \details
     * Возможные значения: 0...65535
     */
    uint16_t level_low() const;

    /**
     * \brief Коррекция верхнего уровня аналогового сигнала
     * \details
     * Возможные значения: 0...65535
     */
    uint16_t level_high() const;

    /**
     * \brief Нижнее аварийное значение сигнала в пользовательском диапазоне,
     * (ед. изм.)
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t alarm_low() const;

    /**
     * \brief Верхнее аварийное значение сигнала в пользовательском диапазоне,
     * (ед. изм.)
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t alarm_high() const;

    /**
     * \brief Наклон характеристики измерительного входа
     * \details
     * Возможные значения: -32768...32767
     * - 0 - 0%
     * - 1000 - 100%
     */
    int16_t slope() const;

    /**
     * \brief Сдвиг характеристики измерительного входа, (ед. изм.)
     * \details
     * Возможные значения: -32768....32767
     */
    int16_t shift() const;

    /**
     * \brief Положение десятичной точки аналогового входа
     * \details
     * Возможные значения: 0...3
     * 
     * Значения по умолчанию:
     * - Для унифицированных аналоговых входов: 2
     * - Для температурных аналоговых входов: 1
     */
    uint16_t decimal() const;

    /**
     * \brief Отключение режекторного фильтра
     * \details
     * Возможные значения:
     * - 0 (false) - Фильтр включен
     * - 1 (true)  - Фильтр отключен
     */
    bool disable_notch_filter() const;

    /**
     * \brief Компенсация температуры холодного спая
     * \details:
     * Возможные значения приведены в перечислении 
     * \ref alphax_parameter::AINPUT_JUNCTION::VALUE
     */
    alphax_parameter::AINPUT_JUNCTION::VALUE junction() const;


    /**
     * \brief Конструктор функционального блока
     * \param init Входные параметры
     */
    AlphaXModule_AnalogInputReadSettings(const Input& init=Input{});

  private:
    ModbusMasterReadSingleRegistersList _request;
    uint8_t _channel;
    etl::vector<modbus_register_pair_t, 13> _read_values;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока настройки аналоговых
   * выходов модулей Alpha-X
   */
  struct AlphaXModule_AnalogOutputSetup_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Настраиваемое устройство
    AlphaXDevice* device{nullptr};
    //! Номер настраиваемого канала
    uint8_t channel{AlphaXModule::AOUTPUT_CHANNEL1};

    //! Записывать тип выходного сигнала
    bool write_type{true};
    //! Записывать нижний предел нормализации аналогового выхода
    bool write_normalize_low{true};
    //! Записывать верхний предел нормализации аналогового выхода
    bool write_normalize_high{true};
    //! Записывать безопасное значение аналогового выхода
    bool write_safe_value{true};

    /**
     * \brief Тип выходного сигнала
     * \details
     * Может принимать значения из перечисления
     * \ref alphax_parameter::AOUTPUT_TYPE::VALUE
     */
    alphax_parameter::AOUTPUT_TYPE::VALUE type{
      alphax_parameter::AOUTPUT_TYPE::UNIFIED_0_20_MA
    };

    /**
     * \brief Нижний предел нормализации аналогового выхода
     * \details
     * Возможные значения: -100...10100
     */
    int16_t normalize_low{0};

    /**
     * \brief Верхний предел нормализации аналогового выхода
     * \details
     * Возможные значения: -100...10100
     */
    int16_t normalize_high{10000};

    /**
     * \brief Безопасное значение аналогового выхода
     * \details
     * Возможные значения: -1000...11000
     */
    int16_t safe_value{0};
  };


  /**
   * \brief Функциональный блок настройки аналоговых выходов Alpha-X
   * \details
   * Настраивает:
   * - Тип выходного сигнала
   * - Диапазон нормализации аналогового выхода
   * - Значение выхода в безопасном состоянии
   * 
   * Не настраивает:
   * - Время задержки перехода выходов в безопасное состояние (общее для всех
   * выходов)
   */
  class AlphaXModule_AnalogOutputSetup
  : public AlphaXModule_AnalogOutputSetup_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = AlphaXModule_AnalogOutputSetup_Input;


    /**
     * \brief Конструктор функционального блока
     * \param init Входные параметры
     */
    AlphaXModule_AnalogOutputSetup(const Input& init=Input{});

  protected:
    ModbusMasterWriteSingleRegistersList _request;
    etl::vector<modbus_register_pair_t, 4> _write_values;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока чтения настроек аналоговых
   * выходов модулей Alpha-X
   */
  struct AlphaXModule_AnalogOutputReadSettings_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Считываемое устройство
    AlphaXDevice* device{nullptr};
    //! Номер считываемого канала
    uint8_t channel{AlphaXModule::AOUTPUT_CHANNEL1};

    //! Считать тип выходного сигнала
    bool read_type{true};
    //! Считать нижний предел нормализации аналогового выхода
    bool read_normalize_low{true};
    //! Считать верхний предел нормализации аналогового выхода
    bool read_normalize_high{true};
    //! Считать безопасное значение аналогового выхода
    bool read_safe_value{true};
  };


  /**
   * \brief Функциональный блок чтения настроек аналоговых выходов Alpha-X
   * \details
   * Считывает:
   * - Тип выходного сигнала
   * - Диапазон нормализации аналогового выхода
   * - Значение выхода в безопасном состоянии
   * 
   * Не считывает:
   * - Время задержки перехода выходов в безопасное состояние (общее для всех
   * выходов)
   */
  class AlphaXModule_AnalogOutputReadSettings
  : public AlphaXModule_AnalogOutputReadSettings_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = AlphaXModule_AnalogOutputReadSettings_Input;

    /**
     * \brief Тип выходного сигнала
     * \details
     * Может принимать значения из перечисления
     * \ref alphax_parameter::AOUTPUT_TYPE::VALUE
     */
    alphax_parameter::AOUTPUT_TYPE::VALUE type() const;

    /**
     * \brief Нижний предел нормализации аналогового выхода
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t normalize_low() const;

    /**
     * \brief Верхний предел нормализации аналогового выхода
     * \details
     * Возможные значения: -32768...32767
     */
    int16_t normalize_high() const;

    /**
     * \brief Безопасное значение аналогового выхода
     * \details
     * Возможные значения: диапазон нормализации аналогового выхода
     */
    int16_t safe_value() const;


    /**
     * \brief Конструктор функционального блока
     * \param init Входные параметры
     */
    AlphaXModule_AnalogOutputReadSettings(const Input& init=Input{});

  protected:
    ModbusMasterReadSingleRegistersList _request;
    uint8_t _channel;
    etl::vector<modbus_register_pair_t, 4> _read_values;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока сброса на заводские
   * настройки модулей Alpha-X
   */
  struct AlphaXModule_FactoryReset_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Настраиваемое устройство
    AlphaXDevice* device{nullptr};

    //! Сбрасывает настройки Modbus
    bool reset_modbus{false};
  };


  /**
   * \brief Функциональный блок сброса на заводские настройки модулей
   * Alpha-X
   * \details
   * Блок отправляет запрос на сброс настроек на заводские и переходит в DONE
   * после завершения операции сброса.
   * 
   * Выполнение ФБ может занимать, в зависимости от версии настраиваемого модуля
   * Alpha-X, до 2 секунд (в среднем 0.6 секунд).
   * Модуль применит новые настройки Modbus в течение максимум 5 секунд после 
   * настройки.
   * 
   * \todo Перевести блок в ETrigATo после добавления сброса функционального
   * блока запросов Modbus
   */
  class AlphaXModule_FactoryReset
  : public AlphaXModule_FactoryReset_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = AlphaXModule_FactoryReset_Input;

    /**
     * \brief Конструктор функционального блока сброса на заводские настройки
     * \param init Значения входных параметров при инициализации
     */
    AlphaXModule_FactoryReset(const Input& init=Input{});

  protected:
    ModbusMasterRequest _request;
    ModbusBuffer<1> _buffer;
    bool _reset_modbus;

    virtual FB_STATE processExecuting() override;
  };


  /**
   * \brief Входные параметры функционального блока сохранения текущих
   * настроек во FLASH-память модулей Alpha-X
   */
  struct AlphaXModule_SaveParameters_Input
  {
    //! Modbus Master для отправки запроса
    ModbusMaster* master{nullptr};
    //! Настраиваемое устройство
    AlphaXDevice* device{nullptr};
    //! Обновляет настройки Modbus после сохранения параметров
    bool config_modbus{true};
  };


  /**
   * \brief Функциональный блок сохранения текущих настроек во FLASH-память
   * модулей Alpha-X
   * \details
   * Блок отправляет запрос на сохранение настроек и переходит в состояние DONE
   * после завершения операции сохранения.
   * 
   * Выполнение ФБ может занимать, в зависимости от версии настраиваемого модуля
   * Alpha-X, до 2 секунд (в среднем 0.6 секунд).
   * 
   * \note Применение настроек Modbus может занимать до 5 секунд после записи
   * в модуль (выполнения функционального блока)
   */
  class AlphaXModule_SaveParameters :
    public AlphaXModule_SaveParameters_Input, public ETrig
  {
  public:
    //! Структура входных параметров функционального блока
    using Input = AlphaXModule_SaveParameters_Input;

    /**
     * \brief Конструктор функционального блока
     */
    AlphaXModule_SaveParameters(const Input& init);

  protected:
    ModbusMasterRequest _request;
    ModbusBuffer<1> _buffer;
    bool _config_modbus;

    virtual FB_STATE processExecuting() override;
  };


  //! Функциональные блоки настройки модуля Alpha-X
  template<>
  struct DeviceSetup<AlphaXModule>
  {
    using DiscreteInputs      = AlphaXModule_DiscreteInputSetup;
    using ReadDiscreteInputs  = AlphaXModule_DiscreteInputReadSettings;
    using DiscreteOutputs     = AlphaXModule_DiscreteOutputSetup;
    using ReadDiscreteOutputs = AlphaXModule_DiscreteOutputReadSettings;
    using AnalogInputs        = AlphaXModule_AnalogInputSetup;
    using ReadAnalogInputs    = AlphaXModule_AnalogInputReadSettings;
    using AnalogOutputs       = AlphaXModule_AnalogOutputSetup;
    using ReadAnalogOutputs   = AlphaXModule_AnalogOutputReadSettings;
    using FactoryReset        = AlphaXModule_FactoryReset;
    using SaveParameters      = AlphaXModule_SaveParameters;
  };

  //! Функциональные блоки настройки модуля Alpha-X DI
  template<>
  struct DeviceSetup<AlphaX_DI>
  {
    using DiscreteInputs      = DeviceSetup<AlphaXModule>::DiscreteInputs;
    using ReadDiscreteInputs  = DeviceSetup<AlphaXModule>::ReadDiscreteInputs;
    using DiscreteOutputs     = void;
    using ReadDiscreteOutputs = void;
    using AnalogInputs        = void;
    using ReadAnalogInputs    = void;
    using AnalogOutputs       = void;
    using ReadAnalogOutputs   = void;
    using FactoryReset        = DeviceSetup<AlphaXModule>::FactoryReset;
    using SaveParameters      = AlphaXModule_SaveParameters;
  };

  //! Функциональные блоки настройки модуля Alpha-X DO
  template<>
  struct DeviceSetup<AlphaX_DO>
  {
    using DiscreteInputs      = void;
    using ReadDiscreteInputs  = void;
    using DiscreteOutputs     = DeviceSetup<AlphaXModule>::DiscreteOutputs;
    using ReadDiscreteOutputs = DeviceSetup<AlphaXModule>::ReadDiscreteOutputs;
    using AnalogInputs        = void;
    using ReadAnalogInputs    = void;
    using AnalogOutputs       = void;
    using ReadAnalogOutputs   = void;
    using FactoryReset        = DeviceSetup<AlphaXModule>::FactoryReset;
    using SaveParameters      = AlphaXModule_SaveParameters;
  };

  //! Функциональные блоки настройки модуля Alpha-X DIO
  template<>
  struct DeviceSetup<AlphaX_DIO>
  {
    using DiscreteInputs      = DeviceSetup<AlphaXModule>::DiscreteInputs;
    using ReadDiscreteInputs  = DeviceSetup<AlphaXModule>::ReadDiscreteInputs;
    using DiscreteOutputs     = DeviceSetup<AlphaXModule>::DiscreteOutputs;
    using ReadDiscreteOutputs = DeviceSetup<AlphaXModule>::ReadDiscreteOutputs;
    using AnalogInputs        = void;
    using ReadAnalogInputs    = void;
    using AnalogOutputs       = void;
    using ReadAnalogOutputs   = void;
    using FactoryReset        = DeviceSetup<AlphaXModule>::FactoryReset;
    using SaveParameters      = AlphaXModule_SaveParameters;
  };

  //! Фунциональные блоки настройки модуля Alpha-X AI
  template<>
  struct DeviceSetup<AlphaX_AI>
  {
    using DiscreteInputs      = void;
    using ReadDiscreteInputs  = void;
    using DiscreteOutputs     = void;
    using ReadDiscreteOutputs = void;
    using AnalogInputs        = DeviceSetup<AlphaXModule>::AnalogInputs;
    using ReadAnalogInputs    = DeviceSetup<AlphaXModule>::ReadAnalogInputs;
    using AnalogOutputs       = void;
    using ReadAnalogOutputs   = DeviceSetup<AlphaXModule>::ReadAnalogOutputs;
    using FactoryReset        = DeviceSetup<AlphaXModule>::FactoryReset;
    using SaveParameters      = AlphaXModule_SaveParameters;
  };
}

