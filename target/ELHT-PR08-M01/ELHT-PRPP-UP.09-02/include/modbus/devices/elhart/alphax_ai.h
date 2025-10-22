/**
 * \file modbus/devices/elhart/alphax_ai.h
 * \brief Модули аналогового ввода Alpha-X AI, опрашиваемые по Modbus
 */

#pragma once

#include "modbus/devices/elhart/alphax_module.h"


namespace modbus::devices::elhart
{
  /**
   * \brief Alpha-X AI Модуль ввода аналоговый
   * \details
   * Класс опрашивает и хранит только оперативные параметры
   */
  class AlphaX_AI : public AlphaXDevice
  {
  public:
    //! Номера групп дискретных входов
    enum DINPUT_GROUP
    {
      //! Группа входов статуса работы аналогового входа №1
      DINPUT_GROUP_AINPUT1_STATUS  = 0,
      //! Группа входов статуса работы аналогового входа №2
      DINPUT_GROUP_AINPUT2_STATUS  = 1,
      //! Группа входов статуса работы аналогового входа №3
      DINPUT_GROUP_AINPUT3_STATUS  = 2,
      //! Группа входов статуса работы аналогового входа №4
      DINPUT_GROUP_AINPUT4_STATUS  = 3,
      //! Группа входов статуса работы аналогового входа №5
      DINPUT_GROUP_AINPUT5_STATUS  = 4,
      //! Группа входов статуса работы аналогового входа №6
      DINPUT_GROUP_AINPUT6_STATUS  = 5,
      //! Группа входов статуса работы аналогового входа №7
      DINPUT_GROUP_AINPUT7_STATUS  = 6,
      //! Группа входов статуса работы аналогового входа №8
      DINPUT_GROUP_AINPUT8_STATUS  = 7,
      //! Кол-во групп дискретных входов
      DINPUT_GROUP_SIZE            = 8
    };

    //! Номера каналов дискретных входов
    enum DINPUT_CHANNEL
    {
      //! Начало каналов статуса аналогового входа №1
      DINPUT_AINPUT1_STATUS_START            = DINPUT_GROUP_AINPUT1_STATUS * 32,
      //! Измерение аналогового входа №1 в норме, ошибки отсутствуют
      DINPUT_AINPUT1_STATUS_NO_ERRORS        = 0 + DINPUT_AINPUT1_STATUS_START,
      //! Измеренное значение аналогового входа №1 выше верхнего аварийного
      DINPUT_AINPUT1_STATUS_ALARM_HIGH       = 1 + DINPUT_AINPUT1_STATUS_START,
      //! Измеренное значение аналогового входа №1 ниже нижнего аварийного
      DINPUT_AINPUT1_STATUS_ALARM_LOW        = 2 + DINPUT_AINPUT1_STATUS_START,
      //! Обрыв датчика аналогового входа №1 (только для датчиков 4..20 мА)
      DINPUT_AINPUT1_STATUS_SENSOR_BREAK     = 3 + DINPUT_AINPUT1_STATUS_START,
      //! Нет связи с АЦП аналогового входа №1
      DINPUT_AINPUT1_STATUS_ADC_ERROR        = 4 + DINPUT_AINPUT1_STATUS_START,
      //! Ошибка компенсации температуры холодного спая аналогового входа №1
      DINPUT_AINPUT1_STATUS_JUNCTION_ERROR   = 5 + DINPUT_AINPUT1_STATUS_START,
      //! Ошибка юстировки аналогового входа №1
      DINPUT_AINPUT1_STATUS_ADJUSTMENT_ERROR = 6 + DINPUT_AINPUT1_STATUS_START,
      //! Кол-во каналов статуса аналогового входа №1
      DINPUT_AINPUT1_STATUS_SIZE             = 7,

      //! Начало каналов статуса аналогового входа №2
      DINPUT_AINPUT2_STATUS_START            = DINPUT_GROUP_AINPUT2_STATUS * 32,
      //! Измерение аналогового входа №2 в норме, ошибки отсутствуют
      DINPUT_AINPUT2_STATUS_NO_ERRORS        = 0 + DINPUT_AINPUT2_STATUS_START,
      //! Измеренное значение аналогового входа №2 выше верхнего аварийного
      DINPUT_AINPUT2_STATUS_ALARM_HIGH       = 1 + DINPUT_AINPUT2_STATUS_START,
      //! Измеренное значение аналогового входа №2 ниже нижнего аварийного
      DINPUT_AINPUT2_STATUS_ALARM_LOW        = 2 + DINPUT_AINPUT2_STATUS_START,
      //! Обрыв датчика аналогового входа №2 (только для датчиков 4..20 мА)
      DINPUT_AINPUT2_STATUS_SENSOR_BREAK     = 3 + DINPUT_AINPUT2_STATUS_START,
      //! Нет связи с АЦП аналогового входа №2
      DINPUT_AINPUT2_STATUS_ADC_ERROR        = 4 + DINPUT_AINPUT2_STATUS_START,
      //! Ошибка компенсации температуры холодного спая аналогового входа №2
      DINPUT_AINPUT2_STATUS_JUNCTION_ERROR   = 5 + DINPUT_AINPUT2_STATUS_START,
      //! Ошибка юстировки аналогового входа №2
      DINPUT_AINPUT2_STATUS_ADJUSTMENT_ERROR = 6 + DINPUT_AINPUT2_STATUS_START,
      //! Кол-во каналов статуса аналогового входа №2
      DINPUT_AINPUT2_STATUS_SIZE             = 7,

      //! Начало каналов статуса аналогового входа №3
      DINPUT_AINPUT3_STATUS_START            = DINPUT_GROUP_AINPUT3_STATUS * 32,
      //! Измерение аналогового входа №3 в норме, ошибки отсутствуют
      DINPUT_AINPUT3_STATUS_NO_ERRORS        = 0 + DINPUT_AINPUT3_STATUS_START,
      //! Измеренное значение аналогового входа №3 выше верхнего аварийного
      DINPUT_AINPUT3_STATUS_ALARM_HIGH       = 1 + DINPUT_AINPUT3_STATUS_START,
      //! Измеренное значение аналогового входа №3 ниже нижнего аварийного
      DINPUT_AINPUT3_STATUS_ALARM_LOW        = 2 + DINPUT_AINPUT3_STATUS_START,
      //! Обрыв датчика аналогового входа №3 (только для датчиков 4..20 мА)
      DINPUT_AINPUT3_STATUS_SENSOR_BREAK     = 3 + DINPUT_AINPUT3_STATUS_START,
      //! Нет связи с АЦП аналогового входа №3
      DINPUT_AINPUT3_STATUS_ADC_ERROR        = 4 + DINPUT_AINPUT3_STATUS_START,
      //! Ошибка компенсации температуры холодного спая аналогового входа №3
      DINPUT_AINPUT3_STATUS_JUNCTION_ERROR   = 5 + DINPUT_AINPUT3_STATUS_START,
      //! Ошибка юстировки аналогового входа №3
      DINPUT_AINPUT3_STATUS_ADJUSTMENT_ERROR = 6 + DINPUT_AINPUT3_STATUS_START,
      //! Кол-во каналов статуса аналогового входа №3
      DINPUT_AINPUT3_STATUS_SIZE             = 7,

      //! Начало каналов статуса аналогового входа №4
      DINPUT_AINPUT4_STATUS_START            = DINPUT_GROUP_AINPUT4_STATUS * 32,
      //! Измерение аналогового входа №4 в норме, ошибки отсутствуют
      DINPUT_AINPUT4_STATUS_NO_ERRORS        = 0 + DINPUT_AINPUT4_STATUS_START,
      //! Измеренное значение аналогового входа №4 выше верхнего аварийного
      DINPUT_AINPUT4_STATUS_ALARM_HIGH       = 1 + DINPUT_AINPUT4_STATUS_START,
      //! Измеренное значение аналогового входа №4 ниже нижнего аварийного
      DINPUT_AINPUT4_STATUS_ALARM_LOW        = 2 + DINPUT_AINPUT4_STATUS_START,
      //! Обрыв датчика аналогового входа №4 (только для датчиков 4..20 мА)
      DINPUT_AINPUT4_STATUS_SENSOR_BREAK     = 3 + DINPUT_AINPUT4_STATUS_START,
      //! Нет связи с АЦП аналогового входа №4
      DINPUT_AINPUT4_STATUS_ADC_ERROR        = 4 + DINPUT_AINPUT4_STATUS_START,
      //! Ошибка компенсации температуры холодного спая аналогового входа №4
      DINPUT_AINPUT4_STATUS_JUNCTION_ERROR   = 5 + DINPUT_AINPUT4_STATUS_START,
      //! Ошибка юстировки аналогового входа №4
      DINPUT_AINPUT4_STATUS_ADJUSTMENT_ERROR = 6 + DINPUT_AINPUT4_STATUS_START,
      //! Кол-во каналов статуса аналогового входа №4
      DINPUT_AINPUT4_STATUS_SIZE             = 7,

      //! Начало каналов статуса аналогового входа №5
      DINPUT_AINPUT5_STATUS_START            = DINPUT_GROUP_AINPUT5_STATUS * 32,
      //! Измерение аналогового входа №5 в норме, ошибки отсутствуют
      DINPUT_AINPUT5_STATUS_NO_ERRORS        = 0 + DINPUT_AINPUT5_STATUS_START,
      //! Измеренное значение аналогового входа №5 выше верхнего аварийного
      DINPUT_AINPUT5_STATUS_ALARM_HIGH       = 1 + DINPUT_AINPUT5_STATUS_START,
      //! Измеренное значение аналогового входа №5 ниже нижнего аварийного
      DINPUT_AINPUT5_STATUS_ALARM_LOW        = 2 + DINPUT_AINPUT5_STATUS_START,
      //! Обрыв датчика аналогового входа №5 (только для датчиков 4..20 мА)
      DINPUT_AINPUT5_STATUS_SENSOR_BREAK     = 3 + DINPUT_AINPUT5_STATUS_START,
      //! Нет связи с АЦП аналогового входа №5
      DINPUT_AINPUT5_STATUS_ADC_ERROR        = 4 + DINPUT_AINPUT5_STATUS_START,
      //! Ошибка компенсации температуры холодного спая аналогового входа №5
      DINPUT_AINPUT5_STATUS_JUNCTION_ERROR   = 5 + DINPUT_AINPUT5_STATUS_START,
      //! Ошибка юстировки аналогового входа №5
      DINPUT_AINPUT5_STATUS_ADJUSTMENT_ERROR = 6 + DINPUT_AINPUT5_STATUS_START,
      //! Кол-во каналов статуса аналогового входа №5
      DINPUT_AINPUT5_STATUS_SIZE             = 7,

      //! Начало каналов статуса аналогового входа №6
      DINPUT_AINPUT6_STATUS_START            = DINPUT_GROUP_AINPUT6_STATUS * 32,
      //! Измерение аналогового входа №6 в норме, ошибки отсутствуют
      DINPUT_AINPUT6_STATUS_NO_ERRORS        = 0 + DINPUT_AINPUT6_STATUS_START,
      //! Измеренное значение аналогового входа №6 выше верхнего аварийного
      DINPUT_AINPUT6_STATUS_ALARM_HIGH       = 1 + DINPUT_AINPUT6_STATUS_START,
      //! Измеренное значение аналогового входа №6 ниже нижнего аварийного
      DINPUT_AINPUT6_STATUS_ALARM_LOW        = 2 + DINPUT_AINPUT6_STATUS_START,
      //! Обрыв датчика аналогового входа №6 (только для датчиков 4..20 мА)
      DINPUT_AINPUT6_STATUS_SENSOR_BREAK     = 3 + DINPUT_AINPUT6_STATUS_START,
      //! Нет связи с АЦП аналогового входа №6
      DINPUT_AINPUT6_STATUS_ADC_ERROR        = 4 + DINPUT_AINPUT6_STATUS_START,
      //! Ошибка компенсации температуры холодного спая аналогового входа №6
      DINPUT_AINPUT6_STATUS_JUNCTION_ERROR   = 5 + DINPUT_AINPUT6_STATUS_START,
      //! Ошибка юстировки аналогового входа №6
      DINPUT_AINPUT6_STATUS_ADJUSTMENT_ERROR = 6 + DINPUT_AINPUT6_STATUS_START,
      //! Кол-во каналов статуса аналогового входа №6
      DINPUT_AINPUT6_STATUS_SIZE             = 7,

      //! Начало каналов статуса аналогового входа №7
      DINPUT_AINPUT7_STATUS_START            = DINPUT_GROUP_AINPUT7_STATUS * 32,
      //! Измерение аналогового входа №7 в норме, ошибки отсутствуют
      DINPUT_AINPUT7_STATUS_NO_ERRORS        = 0 + DINPUT_AINPUT7_STATUS_START,
      //! Измеренное значение аналогового входа №7 выше верхнего аварийного
      DINPUT_AINPUT7_STATUS_ALARM_HIGH       = 1 + DINPUT_AINPUT7_STATUS_START,
      //! Измеренное значение аналогового входа №7 ниже нижнего аварийного
      DINPUT_AINPUT7_STATUS_ALARM_LOW        = 2 + DINPUT_AINPUT7_STATUS_START,
      //! Обрыв датчика аналогового входа №7 (только для датчиков 4..20 мА)
      DINPUT_AINPUT7_STATUS_SENSOR_BREAK     = 3 + DINPUT_AINPUT7_STATUS_START,
      //! Нет связи с АЦП аналогового входа №7
      DINPUT_AINPUT7_STATUS_ADC_ERROR        = 4 + DINPUT_AINPUT7_STATUS_START,
      //! Ошибка компенсации температуры холодного спая аналогового входа №7
      DINPUT_AINPUT7_STATUS_JUNCTION_ERROR   = 5 + DINPUT_AINPUT7_STATUS_START,
      //! Ошибка юстировки аналогового входа №7
      DINPUT_AINPUT7_STATUS_ADJUSTMENT_ERROR = 6 + DINPUT_AINPUT7_STATUS_START,
      //! Кол-во каналов статуса аналогового входа №7
      DINPUT_AINPUT7_STATUS_SIZE             = 7,

      //! Начало каналов статуса аналогового входа №8
      DINPUT_AINPUT8_STATUS_START            = DINPUT_GROUP_AINPUT8_STATUS * 32,
      //! Измерение аналогового входа №8 в норме, ошибки отсутствуют
      DINPUT_AINPUT8_STATUS_NO_ERRORS        = 0 + DINPUT_AINPUT8_STATUS_START,
      //! Измеренное значение аналогового входа №8 выше верхнего аварийного
      DINPUT_AINPUT8_STATUS_ALARM_HIGH       = 1 + DINPUT_AINPUT8_STATUS_START,
      //! Измеренное значение аналогового входа №8 ниже нижнего аварийного
      DINPUT_AINPUT8_STATUS_ALARM_LOW        = 2 + DINPUT_AINPUT8_STATUS_START,
      //! Обрыв датчика аналогового входа №8 (только для датчиков 4..20 мА)
      DINPUT_AINPUT8_STATUS_SENSOR_BREAK     = 3 + DINPUT_AINPUT8_STATUS_START,
      //! Нет связи с АЦП аналогового входа №8
      DINPUT_AINPUT8_STATUS_ADC_ERROR        = 4 + DINPUT_AINPUT8_STATUS_START,
      //! Ошибка компенсации температуры холодного спая аналогового входа №8
      DINPUT_AINPUT8_STATUS_JUNCTION_ERROR   = 5 + DINPUT_AINPUT8_STATUS_START,
      //! Ошибка юстировки аналогового входа №8
      DINPUT_AINPUT8_STATUS_ADJUSTMENT_ERROR = 6 + DINPUT_AINPUT8_STATUS_START,
      //! Кол-во каналов статуса аналогового входа №8
      DINPUT_AINPUT8_STATUS_SIZE             = 7
    };

    //! Номера каналов аналоговых входов
    enum AINPUT_CHANNEL
    {
      //! Начало каналов аналоговых входов
      AINPUT_CHANNEL_START = 0,
      //! Измерительный вход №1
      AINPUT_CHANNEL1      = 0 + AINPUT_CHANNEL_START,
      //! Измерительный вход №2
      AINPUT_CHANNEL2      = 1 + AINPUT_CHANNEL_START,
      //! Измерительный вход №3
      AINPUT_CHANNEL3      = 2 + AINPUT_CHANNEL_START,
      //! Измерительный вход №4
      AINPUT_CHANNEL4      = 3 + AINPUT_CHANNEL_START,
      //! Измерительный вход №5
      AINPUT_CHANNEL5      = 4 + AINPUT_CHANNEL_START,
      //! Измерительный вход №6
      AINPUT_CHANNEL6      = 5 + AINPUT_CHANNEL_START,
      //! Измерительный вход №7
      AINPUT_CHANNEL7      = 6 + AINPUT_CHANNEL_START,
      //! Измерительный вход №8
      AINPUT_CHANNEL8      = 7 + AINPUT_CHANNEL_START,
      //! Кол-во аналоговых входов
      AINPUT_CHANNEL_SIZE  = 8
    };

    //! Таблица параметров "Настройки аналоговых входов"
    using AInputsU_Table = alphax_parameter::AInputsU_Table;
    //! Таблица параметров "Настройки Modbus"
    using ModbusTable    = alphax_parameter::ModbusTable;
    //! Таблица параметров "Сохранение параметров"
    using SaveTable      = alphax_parameter::SaveTable;

    /**
     * \brief Описание таблицы оперативных параметров модуля Alpha-X AI
     */
    inline static const menu::TableInfo operate_table_info{
      alphax_parameter::ainput1_float,
      alphax_parameter::ainput2_float,
      alphax_parameter::ainput3_float,
      alphax_parameter::ainput4_float,
      alphax_parameter::ainput5_float,
      alphax_parameter::ainput6_float,
      alphax_parameter::ainput7_float,
      alphax_parameter::ainput8_float,
      alphax_parameter::aoutput1_float,
      alphax_parameter::aoutput2_float,
      alphax_parameter::aoutput3_float,
      alphax_parameter::aoutput4_float,
      alphax_parameter::ainput1_pv,
      alphax_parameter::ainput2_pv,
      alphax_parameter::ainput3_pv,
      alphax_parameter::ainput4_pv,
      alphax_parameter::ainput5_pv,
      alphax_parameter::ainput6_pv,
      alphax_parameter::ainput7_pv,
      alphax_parameter::ainput8_pv,
      alphax_parameter::aoutput1_pv,
      alphax_parameter::aoutput2_pv,
      alphax_parameter::aoutput3_pv,
      alphax_parameter::aoutput4_pv,
      alphax_parameter::ainput1_status,
      alphax_parameter::ainput2_status,
      alphax_parameter::ainput3_status,
      alphax_parameter::ainput4_status,
      alphax_parameter::ainput5_status,
      alphax_parameter::ainput6_status,
      alphax_parameter::ainput7_status,
      alphax_parameter::ainput8_status,
      alphax_parameter::aoutput1_status,
      alphax_parameter::aoutput2_status,
      alphax_parameter::aoutput3_status,
      alphax_parameter::aoutput4_status,
      alphax_parameter::junction_int,
      alphax_parameter::junction_float
    };

    /**
     * \brief Таблица оперативных параметров модуля Alpha-X AI
     */
    class OperateTable : public decltype(menu::Table{operate_table_info})
    {
    public:
      using base_class = decltype(menu::Table{operate_table_info});
      using start_register = etl::integral_constant<
        uint16_t, alphax_parameter::REGISTERS::AINPUT1_FLOAT_LSR
      >;

      OperateTable(elh::mutex* mutex=nullptr)
      : base_class{operate_table_info, mutex}
      {
      }
    };

    //! Мьютекс доступа к параметрам модуля
    elh::mutex mutex{};
    //! Таблица оперативных параметров модуля
    OperateTable operate_menu{&mutex};

    /**
     * \brief Конструктор устройства Alpha-X AI
     * \param address Адрес устройства в сети Modbus
     */
    AlphaX_AI(uint8_t address)
    : AlphaXDevice{{
        {
          {
            .poll_channels {_poll_channel_storage},
            .dinputs       {_dinputs_storage},
            .doutputs      {},
            .ainputs       {_ainputs_storage},
            .aoutputs      {}
          },
          .address {address}
        },
        .doutputs_signal_pos {0},
        .ainputs_status_pos  {DINPUT_GROUP_AINPUT1_STATUS},
        .aoutputs_status_pos {0},
        .dinputs_size        {0},
        .doutputs_size       {0},
        .ainputs_size        {AINPUT_CHANNEL_SIZE},
        .aoutputs_size       {0},
        .operate_parameters  {operate_menu}
      }},
      _operate_poll_channel{{
        {
          .tree       {_operate_tree},
          .auto_write {false}
        },
        .address        {address},
        .function_write {0x10},
        .function_read  {0x03}
      }}
    {
    }

  private:
    const menu::TableNode<1> _operate_root {
      OperateTable::start_register::value, operate_menu
    };
    ModbusTree<1> _operate_tree {_operate_root};
    ModbusPollChannel _operate_poll_channel;

    const etl::array<device::PollChannel*, 1> _poll_channel_storage{
      &_operate_poll_channel
    };
    etl::array<device::DInputsGroup, DINPUT_GROUP_SIZE> _dinputs_storage{
      device::DInputsGroup{DINPUT_AINPUT1_STATUS_SIZE}, // AI1
      device::DInputsGroup{DINPUT_AINPUT2_STATUS_SIZE}, // AI2
      device::DInputsGroup{DINPUT_AINPUT3_STATUS_SIZE}, // AI3
      device::DInputsGroup{DINPUT_AINPUT4_STATUS_SIZE}, // AI4
      device::DInputsGroup{DINPUT_AINPUT5_STATUS_SIZE}, // AI5
      device::DInputsGroup{DINPUT_AINPUT6_STATUS_SIZE}, // AI6
      device::DInputsGroup{DINPUT_AINPUT7_STATUS_SIZE}, // AI7
      device::DInputsGroup{DINPUT_AINPUT8_STATUS_SIZE}  // AI8
    };
    etl::array<device::AInput, AINPUT_CHANNEL_SIZE> _ainputs_storage;

  public:
    // Переменные для обратной совместимости с предыдущими версиями библиотеки

    /**
     * \brief Структура списка групп дискретных входов прошлых версий
     * для обратной совместимости
     * \deprecated
     * \internal
     */
    struct DINPUTS
    {
      /**
       * \brief Перечисление списка групп дискретных входов прошлых версий
       * для обратной совместимости
       * \deprecated
       * \details
       * В новых проектах следует использовать \ref DINPUT_GROUP
       */
      enum NUMBER : uint8_t
      {
        AINPUT1_STATUS  = DINPUT_GROUP_AINPUT1_STATUS,
        AINPUT2_STATUS  = DINPUT_GROUP_AINPUT2_STATUS,
        AINPUT3_STATUS  = DINPUT_GROUP_AINPUT3_STATUS,
        AINPUT4_STATUS  = DINPUT_GROUP_AINPUT4_STATUS,
        AINPUT5_STATUS  = DINPUT_GROUP_AINPUT5_STATUS,
        AINPUT6_STATUS  = DINPUT_GROUP_AINPUT6_STATUS,
        AINPUT7_STATUS  = DINPUT_GROUP_AINPUT7_STATUS,
        AINPUT8_STATUS  = DINPUT_GROUP_AINPUT8_STATUS,
        SIZE            = DINPUT_GROUP_SIZE
      };
    };

    /**
     * \brief Структура списка каналов аналоговых входов прошлых версий
     * для обратной совместимости
     * \deprecated
     * \internal
     */
    struct AINPUTS
    {
      enum NUMBER : uint8_t
      {
        CHANNEL1 = AINPUT_CHANNEL1,
        CHANNEL2 = AINPUT_CHANNEL2,
        CHANNEL3 = AINPUT_CHANNEL3,
        CHANNEL4 = AINPUT_CHANNEL4,
        CHANNEL5 = AINPUT_CHANNEL5,
        CHANNEL6 = AINPUT_CHANNEL6,
        CHANNEL7 = AINPUT_CHANNEL7,
        CHANNEL8 = AINPUT_CHANNEL8,
        SIZE     = AINPUT_CHANNEL_SIZE
      };
    };
  };
}
