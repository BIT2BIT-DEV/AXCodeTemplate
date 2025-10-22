/**
 * \file modbus/devices/elhart/alphax_module_table.h
 * \brief Таблица параметров модулей Alpha-X
 * \ingroup modbus_devices_elhart_alphax_parameter
 */

#pragma once

#include "modbus/devices/elhart/alphax_module_registers.h"


/**
 * \brief Описание модуля ввода/вывода Alpha-X
 * \ingroup modbus_devices_elhart_alphax_parameter
 */
namespace modbus::devices::elhart::alphax_parameter
{
  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_operate Оперативные параметры
   * \{
   */

  //! Состояние дискретных входов (битовая маска)
  inline const menu::var<uint16_t> dinputs;
  //! Состояние дискретных выходов (битовая маска)
  inline const menu::var<uint16_t> doutputs;
  //! Наличие физического сигнала на дискретных входах (битовая маска)
  inline const menu::var<uint16_t> dinputs_signal;
  //! Фактическое состояние дискретных выходов (битовая маска)
  inline const menu::var<uint16_t> doutputs_signal;


  //! Показания в формате INT16 аналогового входа №1
  inline const menu::var<int16_t> ainput1_int;
  //! Показания в формате INT16 аналогового входа №2
  inline const menu::var<int16_t> ainput2_int;
  //! Показания в формате INT16 аналогового входа №3
  inline const menu::var<int16_t> ainput3_int;
  //! Показания в формате INT16 аналогового входа №4
  inline const menu::var<int16_t> ainput4_int;
  //! Показания в формате INT16 аналогового входа №5
  inline const menu::var<int16_t> ainput5_int;
  //! Показания в формате INT16 аналогового входа №6
  inline const menu::var<int16_t> ainput6_int;
  //! Показания в формате INT16 аналогового входа №7
  inline const menu::var<int16_t> ainput7_int;
  //! Показания в формате INT16 аналогового входа №8
  inline const menu::var<int16_t> ainput8_int;


  //! Значение в формате INT16 аналогового выхода №1
  inline const menu::var<int16_t> aoutput1_int;
  //! Значение в формате INT16 аналогового выхода №2
  inline const menu::var<int16_t> aoutput2_int;
  //! Значение в формате INT16 аналогового выхода №3
  inline const menu::var<int16_t> aoutput3_int;
  //! Значение в формате INT16 аналогового выхода №4
  inline const menu::var<int16_t> aoutput4_int;


  //! Значение в формате Float аналогового входа №1
  inline const menu::var<float> ainput1_float;
  //! Значение в формате Float аналогового входа №2
  inline const menu::var<float> ainput2_float;
  //! Значение в формате Float аналогового входа №3
  inline const menu::var<float> ainput3_float;
  //! Значение в формате Float аналогового входа №4
  inline const menu::var<float> ainput4_float;
  //! Значение в формате Float аналогового входа №5
  inline const menu::var<float> ainput5_float;
  //! Значение в формате Float аналогового входа №6
  inline const menu::var<float> ainput6_float;
  //! Значение в формате Float аналогового входа №7
  inline const menu::var<float> ainput7_float;
  //! Значение в формате Float аналогового входа №8
  inline const menu::var<float> ainput8_float;


  //! Значение в формате Float аналогового выхода №1
  inline const menu::var<float> aoutput1_float;
  //! Значение в формате Float аналогового выхода №2
  inline const menu::var<float> aoutput2_float;
  //! Значение в формате Float аналогового выхода №3
  inline const menu::var<float> aoutput3_float;
  //! Значение в формате Float аналогового выхода №4
  inline const menu::var<float> aoutput4_float;


  //! Показания физической величины сигнала аналогового входа №1
  inline const menu::var<int16_t> ainput1_pv;
  //! Показания физической величины сигнала аналогового входа №2
  inline const menu::var<int16_t> ainput2_pv;
  //! Показания физической величины сигнала аналогового входа №3
  inline const menu::var<int16_t> ainput3_pv;
  //! Показания физической величины сигнала аналогового входа №4
  inline const menu::var<int16_t> ainput4_pv;
  //! Показания физической величины сигнала аналогового входа №5
  inline const menu::var<int16_t> ainput5_pv;
  //! Показания физической величины сигнала аналогового входа №6
  inline const menu::var<int16_t> ainput6_pv;
  //! Показания физической величины сигнала аналогового входа №7
  inline const menu::var<int16_t> ainput7_pv;
  //! Показания физической величины сигнала аналогового входа №8
  inline const menu::var<int16_t> ainput8_pv;


  //! Показания физической величины сигнала аналогового выхода №1
  inline const menu::var<int16_t> aoutput1_pv;
  //! Показания физической величины сигнала аналогового выхода №2
  inline const menu::var<int16_t> aoutput2_pv;
  //! Показания физической величины сигнала аналогового выхода №3
  inline const menu::var<int16_t> aoutput3_pv;
  //! Показания физической величины сигнала аналогового выхода №4
  inline const menu::var<int16_t> aoutput4_pv;


  //! Значения параметра "Статус работы аналогового входа №x"
  struct AINPUT_STATUS
  {
    // Номера бит значений параметра
    enum BIT_NUMBER
    {
      //! Номер бита "Измерение в норме, ошибки отсутствуют"
      NO_ERRORS_BIT        = 0,
      //! Номер бита "Измеренное значение выше верхнего аварийного"
      ALARM_HIGH_BIT       = 1,
      //! Номер бита "Измеренное значение ниже нижнего аварийного"
      ALARM_LOW_BIT        = 2,
      //! Номер бита "Обрыв датчика (только для датчиков 4...20 мА)"
      SENSOR_BREAK_BIT     = 3,
      //! Номер бита "Нет связи с АЦП"
      ADC_ERROR_BIT        = 4,
      //! Номер бита "Ошибка компенсации температуры холодного спая"
      JUNCTION_ERROR_BIT   = 5,
      //! Номер бита "Ошибка юстировки"
      ADJUSTMENT_ERROR_BIT = 6,
      //! Кол-во бит в параметре
      BIT_SIZE             = 7
    };

    // Битовая маска значений параметра
    enum BITMASK : uint16_t
    {
      //! Измерение в норме, ошибки отсутствуют
      NO_ERRORS        = 1 << NO_ERRORS_BIT,
      //! Измеренное значение выше верхнего аварийного
      ALARM_HIGH       = 1 << ALARM_HIGH_BIT,
      //! Измеренное значение ниже нижнего аварийного
      ALARM_LOW        = 1 << ALARM_LOW_BIT,
      //! Обрыв датчика (только для датчиков 4...20 мА)
      SENSOR_BREAK     = 1 << SENSOR_BREAK_BIT,
      //! Нет связи с АЦП
      ADC_ERROR        = 1 << ADC_ERROR_BIT,
      //! Ошибка компенсации температуры холодного спая
      JUNCTION_ERROR   = 1 << JUNCTION_ERROR_BIT,
      //! Ошибка юстировки
      ADJUSTMENT_ERROR = 1 << ADJUSTMENT_ERROR_BIT,
      //! Битовая маска целиком
      ALL = (
        NO_ERRORS | ALARM_HIGH     | ALARM_LOW        | SENSOR_BREAK | 
        ADC_ERROR | JUNCTION_ERROR | ADJUSTMENT_ERROR
      )
    };
  };

  //! Статус работы аналогового входа №1
  inline const menu::var<uint16_t> ainput1_status;
  //! Статус работы аналогового входа №2
  inline const menu::var<uint16_t> ainput2_status;
  //! Статус работы аналогового входа №3
  inline const menu::var<uint16_t> ainput3_status;
  //! Статус работы аналогового входа №4
  inline const menu::var<uint16_t> ainput4_status;
  //! Статус работы аналогового входа №5
  inline const menu::var<uint16_t> ainput5_status;
  //! Статус работы аналогового входа №6
  inline const menu::var<uint16_t> ainput6_status;
  //! Статус работы аналогового входа №7
  inline const menu::var<uint16_t> ainput7_status;
  //! Статус работы аналогового входа №8
  inline const menu::var<uint16_t> ainput8_status;


  //! Значения параметра "Статус работы аналогового выхода №x"
  struct AOUTPUT_STATUS
  {
    //! Номера бит значений параметра
    enum BIT_NUMBER
    {
      //! Номер бита "Сигнал в норме (выход активирован)"
      ENABLED_BIT          = 0,
      //! Номер бита "Аварийное состояние"
      SAFE_STATE_BIT       = 1,
      //! Номер бита "Отсутствует юстировка"
      ADJUSTMENT_ERROR_BIT = 2,
      //! Кол-во бит в параметре
      BIT_SIZE             = 3
    };

    //! Битовая маска значений параметра
    enum BITMASK : uint16_t
    {
      //! Сигнал в норме (выход активирован)
      ENABLED          = 1 << ENABLED_BIT,
      //! Аварийное состояние
      SAFE_STATE       = 1 << SAFE_STATE_BIT,
      //! Отсутствует юстировка
      ADJUSTMENT_ERROR = 1 << ADJUSTMENT_ERROR_BIT,
      //! Битовая маска целиком
      ALL = ENABLED | SAFE_STATE | ADJUSTMENT_ERROR
    };
  };

  //! Статус работы аналогового выхода №1
  inline const menu::var<uint16_t> aoutput1_status;
  //! Статус работы аналогового выхода №2
  inline const menu::var<uint16_t> aoutput2_status;
  //! Статус работы аналогового выхода №3
  inline const menu::var<uint16_t> aoutput3_status;
  //! Статус работы аналогового выхода №4
  inline const menu::var<uint16_t> aoutput4_status;


  //! Значение в формате INT16 температуры холодного спая
  inline const menu::var<int16_t> junction_int;
  //! Значение в формате Float температуры холодного спая
  inline const menu::var<float> junction_float;


  /**
   * \brief Описание таблицы оперативных параметров
   */
  inline const menu::TableInfo operate_table_info{
    dinputs,
    doutputs,
    dinputs_signal,
    doutputs_signal,
    ainput1_int,
    ainput2_int,
    ainput3_int,
    ainput4_int,
    ainput5_int,
    ainput6_int,
    ainput7_int,
    ainput8_int,
    aoutput1_int,
    aoutput2_int,
    aoutput3_int,
    aoutput4_int,
    ainput1_float,
    ainput2_float,
    ainput3_float,
    ainput4_float,
    ainput5_float,
    ainput6_float,
    ainput7_float,
    ainput8_float,
    aoutput1_float,
    aoutput2_float,
    aoutput3_float,
    aoutput4_float,
    ainput1_pv,
    ainput2_pv,
    ainput3_pv,
    ainput4_pv,
    ainput5_pv,
    ainput6_pv,
    ainput7_pv,
    ainput8_pv,
    aoutput1_pv,
    aoutput2_pv,
    aoutput3_pv,
    aoutput4_pv,
    ainput1_status,
    ainput2_status,
    ainput3_status,
    ainput4_status,
    ainput5_status,
    ainput6_status,
    ainput7_status,
    ainput8_status,
    aoutput1_status,
    aoutput2_status,
    aoutput3_status,
    aoutput4_status,
    junction_int,
    junction_float
  };


  /**
   * \brief Таблица оперативных параметров
   */
  class OperateTable : public decltype(menu::Table{operate_table_info})
  {
  public:
    using base_class = decltype(menu::Table{operate_table_info});
    using start_register = etl::integral_constant<uint16_t, REGISTERS::DINPUTS>;

    OperateTable(elh::mutex* mutex=nullptr)
    : base_class{operate_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_operate
   */

  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_counters Счетчики и частотомеры
   * \{
   */

  //! Значение счетчика 32-bit №1
  inline const menu::var<uint32_t> counter1;
  //! Значение счетчика 32-bit №2
  inline const menu::var<uint32_t> counter2;
  //! Значение счетчика 32-bit №3
  inline const menu::var<uint32_t> counter3;
  //! Значение счетчика 32-bit №4
  inline const menu::var<uint32_t> counter4;


  //! Значения параметра "Настройка входов счетчика №X"
  struct COUNTER_INPUT_SETUP
  {
    enum BITMASK : uint16_t
    {
      NONE                     = 0x00, //!< Все отключено

      DINPUT_INCREMENT_DISABLE = 0x00, //!< Инкремент по входу отключен
      DINPUT_INCREMENT_ENABLE  = 0x01, //!< Инкремент по входу включен

      DINPUT_DECREMENT_DISABLE = 0x00, //!< Декремент по входу отключен
      DINPUT_DECREMENT_ENABLE  = 0x02, //!< Декремент по входу включен

      DINPUT_RESET_DISABLE     = 0x00, //!< Сброс по входу отключен
      DINPUT_RESET_ENABLE      = 0x04, //!< Сброс по входу включен

      DINPUT_PAUSE_DISABLE     = 0x00, //!< Пауза счета по входу отключена
      DINPUT_PAUSE_ENABLE      = 0x08, //!< Пауза счета по входу включена

      ALL                      = 0x0F  //!< Битовая маска всех настроек
    };
  };

  //! Настройки входов счетчика №1
  inline const menu::var<uint16_t> counter1_input_setup{{
    .default_value {COUNTER_INPUT_SETUP::NONE},
    .max_value     {COUNTER_INPUT_SETUP::ALL}
  }};
  //! Настройки входов счетчика №2
  inline const menu::var<uint16_t> counter2_input_setup{
    counter1_input_setup
  };
  //! Настройки входов счетчика №3
  inline const menu::var<uint16_t> counter3_input_setup{
    counter1_input_setup
  };
  //! Настройки входов счетчика №4
  inline const menu::var<uint16_t> counter4_input_setup{
    counter1_input_setup
  };


  //! Значения параметра "Управление счетчиком №X"
  struct COUNTER_CONTROL
  {
    enum BITMASK : uint8_t
    {
      NONE  = 0x00, //!< Нет действия
      RESET = 0x01, //!< Сброс значения счетчика
      PAUSE = 0x02, //!< Активация паузы счетчика
      ALL   = 0x03  //!< Битовая маска всех настроек
    };
  };

  //! Управление счетчиком №1
  inline const menu::var<uint16_t> counter1_control{{
    .default_value {COUNTER_CONTROL::NONE},
    .max_value     {COUNTER_CONTROL::ALL}
  }};
  //! Управление счетчиком №2
  inline const menu::var<uint16_t> counter2_control{
    counter1_control
  };
  //! Управление счетчиком №3
  inline const menu::var<uint16_t> counter3_control{
    counter1_control
  };
  //! Управление счетчиком №4
  inline const menu::var<uint16_t> counter4_control{
    counter1_control
  };


  //! Частотомер №1, Гц * 10
  inline const menu::var<uint16_t> frequency_meter_1;
  //! Частотомер №2, Гц * 10
  inline const menu::var<uint16_t> frequency_meter_2;
  //! Частотомер №3, Гц * 10
  inline const menu::var<uint16_t> frequency_meter_3;
  //! Частотомер №4, Гц * 10
  inline const menu::var<uint16_t> frequency_meter_4;


  //! Время определения частоты для частотомера №1, с
  inline const menu::var<uint16_t> frequency_period_1{{
    .default_value {10},
    .min_value     {1},
    .max_value     {60}
  }};
  //! Время определения частоты для частотомера №2, с
  inline const menu::var<uint16_t> frequency_period_2{
    frequency_period_1
  };
  //! Время определения частоты для частотомера №3, с
  inline const menu::var<uint16_t> frequency_period_3{
    frequency_period_1
  };
  //! Время определения частоты для частотомера №4, с
  inline const menu::var<uint16_t> frequency_period_4{
    frequency_period_1
  };


  /**
   * \brief Описание таблицы параметров "Счетчики и частотомеры"
   */
  inline const menu::TableInfo counters_table_info{
    counter1,
    counter2,
    counter3,
    counter4,
    counter1_input_setup,
    counter2_input_setup,
    counter3_input_setup,
    counter4_input_setup,
    counter1_control,
    counter2_control,
    counter3_control,
    counter4_control,
    frequency_meter_1,
    frequency_meter_2,
    frequency_meter_3,
    frequency_meter_4,
    frequency_period_1,
    frequency_period_2,
    frequency_period_3,
    frequency_period_4
  };


  /**
   * \brief Таблица параметров "Счетчики и частотомеры"
   */
  class CountersTable : public decltype(menu::Table{counters_table_info})
  {
  public:
    using base_class = decltype(menu::Table{counters_table_info});
    using start_register = 
      etl::integral_constant<uint16_t, REGISTERS::COUNTER1_VALUE_LSR>;
  
    CountersTable(elh::mutex* mutex=nullptr)
    : base_class{counters_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_counters
   */

  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_pwm Настройки ШИМ
   * \{
   */

  //! Период ШИМ выхода DO1, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do1{{
    .default_value {0},
    .min_value     {0},
    .max_value     {10000}
  }};
  //! Период ШИМ выхода DO2, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do2{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO3, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do3{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO4, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do4{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO5, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do5{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO6, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do6{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO7, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do7{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO8, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do8{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO9, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do9{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO10, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do10{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO11, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do11{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO12, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do12{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO13, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do13{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO14, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do14{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO15, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do15{
    pwm_period_do1
  };
  //! Период ШИМ выхода DO16, x * 100 мс
  inline const menu::var<uint16_t> pwm_period_do16{
    pwm_period_do1
  };


  //! Скважность ШИМ выхода DO1, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do1{{
    .default_value {0},
    .min_value     {0},
    .max_value     {10000}
  }};
  //! Скважность ШИМ выхода DO2, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do2{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO3, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do3{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO4, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do4{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO5, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do5{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO6, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do6{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO7, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do7{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO8, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do8{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO9, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do9{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO10, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do10{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO11, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do11{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO12, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do12{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO13, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do13{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO14, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do14{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO15, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do15{
    pwm_duty_cycle_do1
  };
  //! Скважность ШИМ выхода DO16, % * 100
  inline const menu::var<uint16_t> pwm_duty_cycle_do16{
    pwm_duty_cycle_do1
  };


  /**
   * \brief Описание таблицы параметров "Настройки ШИМ"
   */
  inline const menu::TableInfo pwm_table_info{
    pwm_period_do1,
    pwm_period_do2,
    pwm_period_do3,
    pwm_period_do4,
    pwm_period_do5,
    pwm_period_do6,
    pwm_period_do7,
    pwm_period_do8,
    pwm_period_do9,
    pwm_period_do10,
    pwm_period_do11,
    pwm_period_do12,
    pwm_period_do13,
    pwm_period_do14,
    pwm_period_do15,
    pwm_period_do16,
    pwm_duty_cycle_do1,
    pwm_duty_cycle_do2,
    pwm_duty_cycle_do3,
    pwm_duty_cycle_do4,
    pwm_duty_cycle_do5,
    pwm_duty_cycle_do6,
    pwm_duty_cycle_do7,
    pwm_duty_cycle_do8,
    pwm_duty_cycle_do9,
    pwm_duty_cycle_do10,
    pwm_duty_cycle_do11,
    pwm_duty_cycle_do12,
    pwm_duty_cycle_do13,
    pwm_duty_cycle_do14,
    pwm_duty_cycle_do15,
    pwm_duty_cycle_do16
  };


  /**
   * \brief Таблица параметров "Настройки ШИМ"
   */
  class PWM_Table : public decltype(menu::Table{pwm_table_info})
  {
  public:
    using base_class = decltype(menu::Table{pwm_table_info});
    using start_register =
      etl::integral_constant<uint16_t, REGISTERS::PWM_PERIOD_DO1>;
  
    PWM_Table(elh::mutex* mutex=nullptr)
    : base_class{pwm_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_pwm
   */

  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_dinputs Настройки дискретных входов
   * \{
   */

  //! Значения параметра "Логика работы входов НЗ/НО, битовая маска"
  struct DINPUTS_NO_NC
  {
    enum BITMASK
    {
      NO_ALL  = 0x0000, //!< Все входы имеют НО-контакт

      DI1_NO  = 0x0000, //!< НО-контакт входа №1
      DI2_NO  = 0x0000, //!< НО-контакт входа №2
      DI3_NO  = 0x0000, //!< НО-контакт входа №3
      DI4_NO  = 0x0000, //!< НО-контакт входа №4
      DI5_NO  = 0x0000, //!< НО-контакт входа №5
      DI6_NO  = 0x0000, //!< НО-контакт входа №6
      DI7_NO  = 0x0000, //!< НО-контакт входа №7
      DI8_NO  = 0x0000, //!< НО-контакт входа №8
      DI9_NO  = 0x0000, //!< НО-контакт входа №9
      DI10_NO = 0x0000, //!< НО-контакт входа №10
      DI11_NO = 0x0000, //!< НО-контакт входа №11
      DI12_NO = 0x0000, //!< НО-контакт входа №12
      DI13_NO = 0x0000, //!< НО-контакт входа №13
      DI14_NO = 0x0000, //!< НО-контакт входа №14
      DI15_NO = 0x0000, //!< НО-контакт входа №15
      DI16_NO = 0x0000, //!< НО-контакт входа №16

      NC_ALL  = 0xFFFF, //!< Все входы имеют НЗ-контакт

      DI1_NC  = 0x0001, //!< НЗ-контакт входа №1
      DI2_NC  = 0x0002, //!< НЗ-контакт входа №2
      DI3_NC  = 0x0004, //!< НЗ-контакт входа №3
      DI4_NC  = 0x0008, //!< НЗ-контакт входа №4
      DI5_NC  = 0x0010, //!< НЗ-контакт входа №5
      DI6_NC  = 0x0020, //!< НЗ-контакт входа №6
      DI7_NC  = 0x0040, //!< НЗ-контакт входа №7
      DI8_NC  = 0x0080, //!< НЗ-контакт входа №8
      DI9_NC  = 0x0100, //!< НЗ-контакт входа №9
      DI10_NC = 0x0200, //!< НЗ-контакт входа №10
      DI11_NC = 0x0400, //!< НЗ-контакт входа №11
      DI12_NC = 0x0800, //!< НЗ-контакт входа №12
      DI13_NC = 0x1000, //!< НЗ-контакт входа №13
      DI14_NC = 0x2000, //!< НЗ-контакт входа №14
      DI15_NC = 0x4000, //!< НЗ-контакт входа №15
      DI16_NC = 0x8000  //!< НЗ-контакт входа №16
    };
  };

  //! Логика работы входов НЗ/НО, битовая маска
  inline const menu::var<uint16_t> dinputs_no_nc{{
    .default_value {DINPUTS_NO_NC::NO_ALL},
    .min_value     {DINPUTS_NO_NC::NO_ALL},
    .max_value     {DINPUTS_NO_NC::NC_ALL}
  }};


  //! Задержка включения (TON) DI1, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di1{{
    .default_value {20},
    .min_value     {0},
    .max_value     {50000}
  }};
  //! Задержка включения (TON) DI2, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di2{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI3, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di3{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI4, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di4{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI5, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di5{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI6, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di6{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI7, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di7{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI8, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di8{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI9, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di9{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI10, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di10{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI11, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di11{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI12, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di12{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI13, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di13{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI14, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di14{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI15, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di15{
    dinput_ton_di1
  };
  //! Задержка включения (TON) DI16, x * 500 мкс
  inline const menu::var<uint16_t> dinput_ton_di16{
    dinput_ton_di1
  };


  //! Задержка выключения (TOF) DI1, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di1{{
    .default_value {20},
    .min_value     {0},
    .max_value     {50000}
  }};
  //! Задержка выключения (TOF) DI2, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di2{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI3, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di3{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI4, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di4{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI5, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di5{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI6, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di6{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI7, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di7{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI8, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di8{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI9, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di9{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI10, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di10{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI11, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di11{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI12, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di12{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI13, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di13{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI14, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di14{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI15, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di15{
    dinput_tof_di1
  };
  //! Задержка выключения (TOF) DI16, x * 500 мкс
  inline const menu::var<uint16_t> dinput_tof_di16{
    dinput_tof_di1
  };


  /**
   * \brief Описание таблицы параметров "Настройки дискретных входов"
   */
  inline const menu::TableInfo dinputs_table_info{
    dinputs_no_nc,
    dinput_ton_di1,
    dinput_ton_di2,
    dinput_ton_di3,
    dinput_ton_di4,
    dinput_ton_di5,
    dinput_ton_di6,
    dinput_ton_di7,
    dinput_ton_di8,
    dinput_ton_di9,
    dinput_ton_di10,
    dinput_ton_di11,
    dinput_ton_di12,
    dinput_ton_di13,
    dinput_ton_di14,
    dinput_ton_di15,
    dinput_ton_di16,
    dinput_tof_di1,
    dinput_tof_di2,
    dinput_tof_di3,
    dinput_tof_di4,
    dinput_tof_di5,
    dinput_tof_di6,
    dinput_tof_di7,
    dinput_tof_di8,
    dinput_tof_di9,
    dinput_tof_di10,
    dinput_tof_di11,
    dinput_tof_di12,
    dinput_tof_di13,
    dinput_tof_di14,
    dinput_tof_di15,
    dinput_tof_di16
  };


  /**
   * \brief Таблица параметров "Настройки дискретных входов"
   */
  class DInputsTable : public decltype(menu::Table{dinputs_table_info})
  {
  public:
    using base_class = decltype(menu::Table{dinputs_table_info});
    using start_register =
      etl::integral_constant<uint16_t, REGISTERS::DINPUTS_NO_NC>;

    DInputsTable(elh::mutex* mutex=nullptr)
    : base_class{dinputs_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_dinputs
   */

  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_doutputs Настройки дискретных выходов
   * \{
   */

  //! Значения параметра "Безопасное состояние дискретных выходов"
  struct DOUTPUTS_SAFE_STATE
  {
    enum BITMASK
    {
      ALL_OFF    = 0x0000, //!< Контакты всех выходов отключены

      DOUT1_OFF  = 0x0000, //!< Контакт выхода №1 отключен
      DOUT2_OFF  = 0x0000, //!< Контакт выхода №2 отключен
      DOUT3_OFF  = 0x0000, //!< Контакт выхода №3 отключен
      DOUT4_OFF  = 0x0000, //!< Контакт выхода №4 отключен
      DOUT5_OFF  = 0x0000, //!< Контакт выхода №5 отключен
      DOUT6_OFF  = 0x0000, //!< Контакт выхода №6 отключен
      DOUT7_OFF  = 0x0000, //!< Контакт выхода №7 отключен
      DOUT8_OFF  = 0x0000, //!< Контакт выхода №8 отключен
      DOUT9_OFF  = 0x0000, //!< Контакт выхода №9 отключен
      DOUT10_OFF = 0x0000, //!< Контакт выхода №10 отключен
      DOUT11_OFF = 0x0000, //!< Контакт выхода №11 отключен
      DOUT12_OFF = 0x0000, //!< Контакт выхода №12 отключен
      DOUT13_OFF = 0x0000, //!< Контакт выхода №13 отключен
      DOUT14_OFF = 0x0000, //!< Контакт выхода №14 отключен
      DOUT15_OFF = 0x0000, //!< Контакт выхода №15 отключен
      DOUT16_OFF = 0x0000, //!< Контакт выхода №16 отключен

      ALL_ON     = 0xFFFF, //!< Контакты всех выходов включены

      DOUT_ON1   = 0x0001, //!< Контакт выхода №1 включен
      DOUT_ON2   = 0x0002, //!< Контакт выхода №2 включен
      DOUT_ON3   = 0x0004, //!< Контакт выхода №3 включен
      DOUT_ON4   = 0x0008, //!< Контакт выхода №4 включен
      DOUT_ON5   = 0x0010, //!< Контакт выхода №5 включен
      DOUT_ON6   = 0x0020, //!< Контакт выхода №6 включен
      DOUT_ON7   = 0x0040, //!< Контакт выхода №7 включен
      DOUT_ON8   = 0x0080, //!< Контакт выхода №8 включен
      DOUT_ON9   = 0x0100, //!< Контакт выхода №9 включен
      DOUT_ON10  = 0x0200, //!< Контакт выхода №10 включен
      DOUT_ON11  = 0x0400, //!< Контакт выхода №11 включен
      DOUT_ON12  = 0x0800, //!< Контакт выхода №12 включен
      DOUT_ON13  = 0x1000, //!< Контакт выхода №13 включен
      DOUT_ON14  = 0x2000, //!< Контакт выхода №14 включен
      DOUT_ON15  = 0x4000, //!< Контакт выхода №15 включен
      DOUT_ON16  = 0x8000, //!< Контакт выхода №16 включен
    };
  };

  //! Безопасное состояние дискретных выходов, битовая маска
  inline const menu::var<uint16_t> doutputs_safe_state{{
    .default_value {DOUTPUTS_SAFE_STATE::ALL_OFF},
    .min_value     {DOUTPUTS_SAFE_STATE::ALL_OFF},
    .max_value     {DOUTPUTS_SAFE_STATE::ALL_ON}
  }};


  /**
   * \brief Задержка перехода выходов в безопасное состояние, x * с
   * \details
   * Значение "0" - функция отключена
   */
  inline const menu::var<uint16_t> doutputs_safe_state_delay{{
    .default_value {0},
    .min_value     {0},
    .max_value     {65535}
  }};


  //! Задержка включения (TON) DO1, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do1{{
    .default_value {0},
    .min_value     {0},
    .max_value     {1000}
  }};
  //! Задержка включения (TON) DO2, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do2{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO3, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do3{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO4, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do4{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO5, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do5{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO6, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do6{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO7, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do7{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO8, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do8{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO9, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do9{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO10, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do10{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO11, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do11{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO12, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do12{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO13, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do13{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO14, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do14{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO15, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do15{
    doutput_ton_do1
  };
  //! Задержка включения (TON) DO16, x * 1 с
  inline const menu::var<uint16_t> doutput_ton_do16{
    doutput_ton_do1
  };


  //! Задержка выключения (TOF) DO1, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do1{{
    .default_value {0},
    .min_value     {0},
    .max_value     {1000}
  }};
  //! Задержка выключения (TOF) DO2, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do2{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO3, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do3{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO4, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do4{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO5, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do5{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO6, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do6{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO7, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do7{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO8, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do8{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO9, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do9{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO10, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do10{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO11, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do11{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO12, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do12{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO13, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do13{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO14, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do14{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO15, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do15{
    doutput_tof_do1
  };
  //! Задержка выключения (TOF) DO16, x * 1 с
  inline const menu::var<uint16_t> doutput_tof_do16{
    doutput_tof_do1
  };


  /**
   * \brief Описание таблицы параметров "Настройки дискретных выходов"
   */
  inline const menu::TableInfo doutputs_table_info{
    doutputs_safe_state,
    doutputs_safe_state_delay,
    doutput_ton_do1,
    doutput_ton_do2,
    doutput_ton_do3,
    doutput_ton_do4,
    doutput_ton_do5,
    doutput_ton_do6,
    doutput_ton_do7,
    doutput_ton_do8,
    doutput_ton_do9,
    doutput_ton_do10,
    doutput_ton_do11,
    doutput_ton_do12,
    doutput_ton_do13,
    doutput_ton_do14,
    doutput_ton_do15,
    doutput_ton_do16,
    doutput_tof_do1,
    doutput_tof_do2,
    doutput_tof_do3,
    doutput_tof_do4,
    doutput_tof_do5,
    doutput_tof_do6,
    doutput_tof_do7,
    doutput_tof_do8,
    doutput_tof_do9,
    doutput_tof_do10,
    doutput_tof_do11,
    doutput_tof_do12,
    doutput_tof_do13,
    doutput_tof_do14,
    doutput_tof_do15,
    doutput_tof_do16
  };


  /**
   * \brief Таблица параметров "Настройки дискретных выходов"
   */
  class DOutputsTable : public decltype(menu::Table{doutputs_table_info})
  {
  public:
    using base_class = decltype(menu::Table{doutputs_table_info});
    using start_register = 
      etl::integral_constant<uint16_t, REGISTERS::DOUTPUTS_SAFE_STATE>;

    DOutputsTable(elh::mutex* mutex=nullptr)
    : base_class{doutputs_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_doutputs
   */

  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_ainputs Настройки аналоговых входов
   * \{
   */

  //! Значения параметра "Тип подключаемого датчика AIx"
  struct AINPUT_TYPE
  {
    enum VALUE
    {
      //! 50М,    α = 0,00428 °С-1
      SENSOR_50M      = 0,
      //! Pt100,  α = 0,00385 °С-1
      SENSOR_PT100    = 6,
      //! 100П,   α = 0,00391 °С-1
      SENSOR_100P     = 7,
      //! Pt1000, α = 0,00385 °С-1
      SENSOR_PT1000   = 15,
      //! J(ТЖК), железо-константан
      SENSOR_J        = 23,
      //! K(ТХА), хромель-алюмель
      SENSOR_K        = 24,
      //! L(ТХК), хромель-копель
      SENSOR_L        = 25,
      //! B(ТПР), платинородий
      SENSOR_B        = 27,
      //! S(ТХА), платинородий-платина (10%)
      SENSOR_S        = 28,
      //! (0...20) мА
      UNIFIED_0_20_MA = 33,
      //! (4...20) мА
      UNIFIED_4_20_MA = 34,
      //! (0...10) В
      UNIFIED_0_10_V  = 36,
      //! Измерительный вход отключен
      DISABLED        = 42
    };
  };

  //! Тип подключаемого датчика AI1
  inline const menu::var<uint16_t> ainput_type_ai1{{
    .default_value {AINPUT_TYPE::UNIFIED_0_10_V},
    .min_value     {AINPUT_TYPE::SENSOR_50M},
    .max_value     {AINPUT_TYPE::DISABLED}
  }};
  //! Тип подключаемого датчика AI2
  inline const menu::var<uint16_t> ainput_type_ai2{
    ainput_type_ai1
  };
  //! Тип подключаемого датчика AI3
  inline const menu::var<uint16_t> ainput_type_ai3{
    ainput_type_ai1
  };
  //! Тип подключаемого датчика AI4
  inline const menu::var<uint16_t> ainput_type_ai4{
    ainput_type_ai1
  };
  //! Тип подключаемого датчика AI5
  inline const menu::var<uint16_t> ainput_type_ai5{
    ainput_type_ai1
  };
  //! Тип подключаемого датчика AI6
  inline const menu::var<uint16_t> ainput_type_ai6{
    ainput_type_ai1
  };
  //! Тип подключаемого датчика AI7
  inline const menu::var<uint16_t> ainput_type_ai7{
    ainput_type_ai1
  };
  //! Тип подключаемого датчика AI8
  inline const menu::var<uint16_t> ainput_type_ai8{
    ainput_type_ai1
  };


  //! Значения параметра "Тип подключаемого датчика унифицированных сигналов"
  struct AINPUT_TYPE_U
  {
    enum VALUE
    {
      //! (0...20) мА
      UNIFIED_0_20_MA = AINPUT_TYPE::UNIFIED_0_20_MA,
      //! (4...20) мА
      UNIFIED_4_20_MA = AINPUT_TYPE::UNIFIED_4_20_MA,
      //! (0...10) В
      UNIFIED_0_10_V  = AINPUT_TYPE::UNIFIED_0_10_V,
      //! Измерительный вход отключен
      DISABLED        = AINPUT_TYPE::DISABLED
    };
  };


  //! Тип подключаемого датчика унифицированных сигналов AI1
  inline const menu::var<uint16_t> ainput_type_u_ai1{{
    .default_value {AINPUT_TYPE_U::UNIFIED_0_10_V},
    .min_value     {AINPUT_TYPE_U::UNIFIED_0_20_MA},
    .max_value     {AINPUT_TYPE_U::DISABLED}
  }};
  //! Тип подключаемого датчика унифицированных сигналов AI2
  inline const menu::var<uint16_t> ainput_type_u_ai2{
    ainput_type_u_ai1
  };
  //! Тип подключаемого датчика унифицированных сигналов AI3
  inline const menu::var<uint16_t> ainput_type_u_ai3{
    ainput_type_u_ai1
  };
  //! Тип подключаемого датчика унифицированных сигналов AI4
  inline const menu::var<uint16_t> ainput_type_u_ai4{
    ainput_type_u_ai1
  };
  //! Тип подключаемого датчика унифицированных сигналов AI5
  inline const menu::var<uint16_t> ainput_type_u_ai5{
    ainput_type_u_ai1
  };
  //! Тип подключаемого датчика унифицированных сигналов AI6
  inline const menu::var<uint16_t> ainput_type_u_ai6{
    ainput_type_u_ai1
  };
  //! Тип подключаемого датчика унифицированных сигналов AI7
  inline const menu::var<uint16_t> ainput_type_u_ai7{
    ainput_type_u_ai1
  };
  //! Тип подключаемого датчика унифицированных сигналов AI8
  inline const menu::var<uint16_t> ainput_type_u_ai8{
    ainput_type_u_ai1
  };


  //! Значения параметра "Тип подключаемого датчика температурных сигналов"
  struct AINPUT_TYPE_T
  {
    enum VALUE
    {
      //! 50М,    α = 0,00428 °С-1
      SENSOR_50M    = AINPUT_TYPE::SENSOR_50M,
      //! Pt100,  α = 0,00385 °С-1
      SENSOR_PT100  = AINPUT_TYPE::SENSOR_PT100,
      //! 100П,   α = 0,00391 °С-1
      SENSOR_100P   = AINPUT_TYPE::SENSOR_100P,
      //! Pt1000, α = 0,00385 °С-1
      SENSOR_PT1000 = AINPUT_TYPE::SENSOR_PT1000,
      //! J(ТЖК), железо-константан
      SENSOR_J      = AINPUT_TYPE::SENSOR_J,
      //! K(ТХА), хромель-алюмель
      SENSOR_K      = AINPUT_TYPE::SENSOR_K,
      //! L(ТХК), хромель-копель
      SENSOR_L      = AINPUT_TYPE::SENSOR_L,
      //! B(ТПР), платинородий
      SENSOR_B      = AINPUT_TYPE::SENSOR_B,
      //! S(ТХА), платинородий-платина (10%)
      SENSOR_S      = AINPUT_TYPE::SENSOR_S,
      //! Измерительный вход отключен
      DISABLED      = AINPUT_TYPE::DISABLED
    };
  };

  //! Тип подключаемого датчика температурных сигналов AI1
  inline const menu::var<uint16_t> ainput_type_t_ai1{{
    .default_value {AINPUT_TYPE_T::SENSOR_50M},
    .min_value     {AINPUT_TYPE_T::SENSOR_50M},
    .max_value     {AINPUT_TYPE_T::DISABLED}
  }};
  //! Тип подключаемого датчика температурных сигналов AI2
  inline const menu::var<uint16_t> ainput_type_t_ai2{
    ainput_type_t_ai1
  };
  //! Тип подключаемого датчика температурных сигналов AI3
  inline const menu::var<uint16_t> ainput_type_t_ai3{
    ainput_type_t_ai1
  };
  //! Тип подключаемого датчика температурных сигналов AI4
  inline const menu::var<uint16_t> ainput_type_t_ai4{
    ainput_type_t_ai1
  };
  //! Тип подключаемого датчика температурных сигналов AI5
  inline const menu::var<uint16_t> ainput_type_t_ai5{
    ainput_type_t_ai1
  };
  //! Тип подключаемого датчика температурных сигналов AI6
  inline const menu::var<uint16_t> ainput_type_t_ai6{
    ainput_type_t_ai1
  };
  //! Тип подключаемого датчика температурных сигналов AI7
  inline const menu::var<uint16_t> ainput_type_t_ai7{
    ainput_type_t_ai1
  };
  //! Тип подключаемого датчика температурных сигналов AI8
  inline const menu::var<uint16_t> ainput_type_t_ai8{
    ainput_type_t_ai1
  };


  //! Степень фильтрации сигнала AI1
  inline const menu::var<uint16_t> ainput_filter_ai1{{
    .default_value {2},
    .min_value     {0},
    .max_value     {8}
  }};
  //! Степень фильтрации сигнала AI2
  inline const menu::var<uint16_t> ainput_filter_ai2{
    ainput_filter_ai1
  };
  //! Степень фильтрации сигнала AI3
  inline const menu::var<uint16_t> ainput_filter_ai3{
    ainput_filter_ai1
  };
  //! Степень фильтрации сигнала AI4
  inline const menu::var<uint16_t> ainput_filter_ai4{
    ainput_filter_ai1
  };
  //! Степень фильтрации сигнала AI5
  inline const menu::var<uint16_t> ainput_filter_ai5{
    ainput_filter_ai1
  };
  //! Степень фильтрации сигнала AI6
  inline const menu::var<uint16_t> ainput_filter_ai6{
    ainput_filter_ai1
  };
  //! Степень фильтрации сигнала AI7
  inline const menu::var<uint16_t> ainput_filter_ai7{
    ainput_filter_ai1
  };
  //! Степень фильтрации сигнала AI8
  inline const menu::var<uint16_t> ainput_filter_ai8{
    ainput_filter_ai1
  };


  //! Нижнее значение для приведения к пользовательской шкале (ед.изм.), AI1
  inline const menu::var<int16_t> ainput_normalize_low_ai1{{
    .default_value {0},
    .min_value     {-32768},
    .max_value     {32767}
  }};
  //! Нижнее значение для приведения к пользовательской шкале (ед.изм.), AI2
  inline const menu::var<int16_t> ainput_normalize_low_ai2{
    ainput_normalize_low_ai1
  };
  //! Нижнее значение для приведения к пользовательской шкале (ед.изм.), AI3
  inline const menu::var<int16_t> ainput_normalize_low_ai3{
    ainput_normalize_low_ai1
  };
  //! Нижнее значение для приведения к пользовательской шкале (ед.изм.), AI4
  inline const menu::var<int16_t> ainput_normalize_low_ai4{
    ainput_normalize_low_ai1
  };
  //! Нижнее значение для приведения к пользовательской шкале (ед.изм.), AI5
  inline const menu::var<int16_t> ainput_normalize_low_ai5{
    ainput_normalize_low_ai1
  };
  //! Нижнее значение для приведения к пользовательской шкале (ед.изм.), AI6
  inline const menu::var<int16_t> ainput_normalize_low_ai6{
    ainput_normalize_low_ai1
  };
  //! Нижнее значение для приведения к пользовательской шкале (ед.изм.), AI7
  inline const menu::var<int16_t> ainput_normalize_low_ai7{
    ainput_normalize_low_ai1
  };
  //! Нижнее значение для приведения к пользовательской шкале (ед.изм.), AI8
  inline const menu::var<int16_t> ainput_normalize_low_ai8{
    ainput_normalize_low_ai1
  };


  //! Верхнее значение для приведения к пользовательской шкале (ед.изм.), AI1
  inline const menu::var<int16_t> ainput_normalize_high_ai1{{
    .default_value {10000},
    .min_value     {-32768},
    .max_value     {32767}
  }};
  //! Верхнее значение для приведения к пользовательской шкале (ед.изм.), AI2
  inline const menu::var<int16_t> ainput_normalize_high_ai2{
    ainput_normalize_high_ai1
  };
  //! Верхнее значение для приведения к пользовательской шкале (ед.изм.), AI3
  inline const menu::var<int16_t> ainput_normalize_high_ai3{
    ainput_normalize_high_ai1
  };
  //! Верхнее значение для приведения к пользовательской шкале (ед.изм.), AI4
  inline const menu::var<int16_t> ainput_normalize_high_ai4{
    ainput_normalize_high_ai1
  };
  //! Верхнее значение для приведения к пользовательской шкале (ед.изм.), AI5
  inline const menu::var<int16_t> ainput_normalize_high_ai5{
    ainput_normalize_high_ai1
  };
  //! Верхнее значение для приведения к пользовательской шкале (ед.изм.), AI6
  inline const menu::var<int16_t> ainput_normalize_high_ai6{
    ainput_normalize_high_ai1
  };
  //! Верхнее значение для приведения к пользовательской шкале (ед.изм.), AI7
  inline const menu::var<int16_t> ainput_normalize_high_ai7{
    ainput_normalize_high_ai1
  };
  //! Верхнее значение для приведения к пользовательской шкале (ед.изм.), AI8
  inline const menu::var<int16_t> ainput_normalize_high_ai8{
    ainput_normalize_high_ai1
  };


  //! Коррекция нижнего уровня аналогового сигнала, AI1
  inline const menu::var<int16_t> ainput_level_low_ai1{{
    .default_value {0},
    .min_value     {-32768},
    .max_value     {32767}
  }};
  //! Коррекция нижнего уровня аналогового сигнала, AI2
  inline const menu::var<int16_t> ainput_level_low_ai2{
    ainput_level_low_ai1
  };
  //! Коррекция нижнего уровня аналогового сигнала, AI3
  inline const menu::var<int16_t> ainput_level_low_ai3{
    ainput_level_low_ai1
  };
  //! Коррекция нижнего уровня аналогового сигнала, AI4
  inline const menu::var<int16_t> ainput_level_low_ai4{
    ainput_level_low_ai1
  };
  //! Коррекция нижнего уровня аналогового сигнала, AI5
  inline const menu::var<int16_t> ainput_level_low_ai5{
    ainput_level_low_ai1
  };
  //! Коррекция нижнего уровня аналогового сигнала, AI6
  inline const menu::var<int16_t> ainput_level_low_ai6{
    ainput_level_low_ai1
  };
  //! Коррекция нижнего уровня аналогового сигнала, AI7
  inline const menu::var<int16_t> ainput_level_low_ai7{
    ainput_level_low_ai1
  };
  //! Коррекция нижнего уровня аналогового сигнала, AI8
  inline const menu::var<int16_t> ainput_level_low_ai8{
    ainput_level_low_ai1
  };


  //! Коррекция верхнего уровня аналогового сигнала, AI1
  inline const menu::var<int16_t> ainput_level_high_ai1{{
    .default_value {10000},
    .min_value     {-32768},
    .max_value     {32767}
  }};
  //! Коррекция верхнего уровня аналогового сигнала, AI2
  inline const menu::var<int16_t> ainput_level_high_ai2{
    ainput_level_high_ai1
  };
  //! Коррекция верхнего уровня аналогового сигнала, AI3
  inline const menu::var<int16_t> ainput_level_high_ai3{
    ainput_level_high_ai1
  };
  //! Коррекция верхнего уровня аналогового сигнала, AI4
  inline const menu::var<int16_t> ainput_level_high_ai4{
    ainput_level_high_ai1
  };
  //! Коррекция верхнего уровня аналогового сигнала, AI5
  inline const menu::var<int16_t> ainput_level_high_ai5{
    ainput_level_high_ai1
  };
  //! Коррекция верхнего уровня аналогового сигнала, AI6
  inline const menu::var<int16_t> ainput_level_high_ai6{
    ainput_level_high_ai1
  };
  //! Коррекция верхнего уровня аналогового сигнала, AI7
  inline const menu::var<int16_t> ainput_level_high_ai7{
    ainput_level_high_ai1
  };
  //! Коррекция верхнего уровня аналогового сигнала, AI8
  inline const menu::var<int16_t> ainput_level_high_ai8{
    ainput_level_high_ai1
  };


  //! Нижнее аварийное значение сигнала в пользовательском диапазоне, AI1
  inline const menu::var<int16_t> ainput_alarm_low_ai1{{
    .default_value {0},
    .min_value     {-32768},
    .max_value     {32767}
  }};
  //! Нижнее аварийное значение сигнала в пользовательском диапазоне, AI2
  inline const menu::var<int16_t> ainput_alarm_low_ai2{
    ainput_alarm_low_ai1
  };
  //! Нижнее аварийное значение сигнала в пользовательском диапазоне, AI3
  inline const menu::var<int16_t> ainput_alarm_low_ai3{
    ainput_alarm_low_ai1
  };
  //! Нижнее аварийное значение сигнала в пользовательском диапазоне, AI4
  inline const menu::var<int16_t> ainput_alarm_low_ai4{
    ainput_alarm_low_ai1
  };
  //! Нижнее аварийное значение сигнала в пользовательском диапазоне, AI5
  inline const menu::var<int16_t> ainput_alarm_low_ai5{
    ainput_alarm_low_ai1
  };
  //! Нижнее аварийное значение сигнала в пользовательском диапазоне, AI6
  inline const menu::var<int16_t> ainput_alarm_low_ai6{
    ainput_alarm_low_ai1
  };
  //! Нижнее аварийное значение сигнала в пользовательском диапазоне, AI7
  inline const menu::var<int16_t> ainput_alarm_low_ai7{
    ainput_alarm_low_ai1
  };
  //! Нижнее аварийное значение сигнала в пользовательском диапазоне, AI8
  inline const menu::var<int16_t> ainput_alarm_low_ai8{
    ainput_alarm_low_ai1
  };


  //! Верхнее аварийное значение сигнала в пользовательском диапазоне, AI1
  inline const menu::var<int16_t> ainput_alarm_high_ai1{{
    .default_value {10000},
    .min_value     {-32768},
    .max_value     {32767}
  }};
  //! Верхнее аварийное значение сигнала в пользовательском диапазоне, AI2
  inline const menu::var<int16_t> ainput_alarm_high_ai2{
    ainput_alarm_high_ai1
  };
  //! Верхнее аварийное значение сигнала в пользовательском диапазоне, AI3
  inline const menu::var<int16_t> ainput_alarm_high_ai3{
    ainput_alarm_high_ai1
  };
  //! Верхнее аварийное значение сигнала в пользовательском диапазоне, AI4
  inline const menu::var<int16_t> ainput_alarm_high_ai4{
    ainput_alarm_high_ai1
  };
  //! Верхнее аварийное значение сигнала в пользовательском диапазоне, AI5
  inline const menu::var<int16_t> ainput_alarm_high_ai5{
    ainput_alarm_high_ai1
  };
  //! Верхнее аварийное значение сигнала в пользовательском диапазоне, AI6
  inline const menu::var<int16_t> ainput_alarm_high_ai6{
    ainput_alarm_high_ai1
  };
  //! Верхнее аварийное значение сигнала в пользовательском диапазоне, AI7
  inline const menu::var<int16_t> ainput_alarm_high_ai7{
    ainput_alarm_high_ai1
  };
  //! Верхнее аварийное значение сигнала в пользовательском диапазоне, AI8
  inline const menu::var<int16_t> ainput_alarm_high_ai8{
    ainput_alarm_high_ai1
  };


  //! Наклон характеристики измерительного входа, AI1
  inline const menu::var<int16_t> ainput_slope_ai1{{
    .default_value {1000},
    .min_value     {-32768},
    .max_value     {32767}
  }};
  //! Наклон характеристики измерительного входа, AI2
  inline const menu::var<int16_t> ainput_slope_ai2{
    ainput_slope_ai1
  };
  //! Наклон характеристики измерительного входа, AI3
  inline const menu::var<int16_t> ainput_slope_ai3{
    ainput_slope_ai1
  };
  //! Наклон характеристики измерительного входа, AI4
  inline const menu::var<int16_t> ainput_slope_ai4{
    ainput_slope_ai1
  };
  //! Наклон характеристики измерительного входа, AI5
  inline const menu::var<int16_t> ainput_slope_ai5{
    ainput_slope_ai1
  };
  //! Наклон характеристики измерительного входа, AI6
  inline const menu::var<int16_t> ainput_slope_ai6{
    ainput_slope_ai1
  };
  //! Наклон характеристики измерительного входа, AI7
  inline const menu::var<int16_t> ainput_slope_ai7{
    ainput_slope_ai1
  };
  //! Наклон характеристики измерительного входа, AI8
  inline const menu::var<int16_t> ainput_slope_ai8{
    ainput_slope_ai1
  };


  //! Сдвиг характеристики измерительного входа, AI1
  inline const menu::var<int16_t> ainput_shift_ai1{{
    .default_value {0},
    .min_value     {-32768},
    .max_value     {32767}
  }};
  //! Сдвиг характеристики измерительного входа, AI2
  inline const menu::var<int16_t> ainput_shift_ai2{
    ainput_shift_ai1
  };
  //! Сдвиг характеристики измерительного входа, AI3
  inline const menu::var<int16_t> ainput_shift_ai3{
    ainput_shift_ai1
  };
  //! Сдвиг характеристики измерительного входа, AI4
  inline const menu::var<int16_t> ainput_shift_ai4{
    ainput_shift_ai1
  };
  //! Сдвиг характеристики измерительного входа, AI5
  inline const menu::var<int16_t> ainput_shift_ai5{
    ainput_shift_ai1
  };
  //! Сдвиг характеристики измерительного входа, AI6
  inline const menu::var<int16_t> ainput_shift_ai6{
    ainput_shift_ai1
  };
  //! Сдвиг характеристики измерительного входа, AI7
  inline const menu::var<int16_t> ainput_shift_ai7{
    ainput_shift_ai1
  };
  //! Сдвиг характеристики измерительного входа, AI8
  inline const menu::var<int16_t> ainput_shift_ai8{
    ainput_shift_ai1
  };


  //! Положение десятичной точки аналогового входа AI1
  inline const menu::var<uint16_t> ainput_decimal_ai1{{
    .default_value {2},
    .min_value     {0},
    .max_value     {3}
  }};
  //! Положение десятичной точки аналогового входа AI2
  inline const menu::var<uint16_t> ainput_decimal_ai2{
    ainput_decimal_ai1
  };
  //! Положение десятичной точки аналогового входа AI3
  inline const menu::var<uint16_t> ainput_decimal_ai3{
    ainput_decimal_ai1
  };
  //! Положение десятичной точки аналогового входа AI4
  inline const menu::var<uint16_t> ainput_decimal_ai4{
    ainput_decimal_ai1
  };
  //! Положение десятичной точки аналогового входа AI5
  inline const menu::var<uint16_t> ainput_decimal_ai5{
    ainput_decimal_ai1
  };
  //! Положение десятичной точки аналогового входа AI6
  inline const menu::var<uint16_t> ainput_decimal_ai6{
    ainput_decimal_ai1
  };
  //! Положение десятичной точки аналогового входа AI7
  inline const menu::var<uint16_t> ainput_decimal_ai7{
    ainput_decimal_ai1
  };
  //! Положение десятичной точки аналогового входа AI8
  inline const menu::var<uint16_t> ainput_decimal_ai8{
    ainput_decimal_ai1
  };


  //! Значения параметра "Отключение режекторного фильтра, AIx"
  struct AINPUT_NOTCH_FILTER
  {
    enum VALUE : uint16_t
    {
      ENABLED  = 0, //!< Фильтр включен
      DISABLED = 1  //!< Фильтр выключен
    };
  };

  //! Отключение режекторного фильтра, AI1
  inline const menu::var<uint16_t> ainput_notch_filter_ai1{{
    .default_value {AINPUT_NOTCH_FILTER::ENABLED},
    .min_value     {AINPUT_NOTCH_FILTER::ENABLED},
    .max_value     {AINPUT_NOTCH_FILTER::DISABLED}
  }};
  //! Отключение режекторного фильтра, AI2
  inline const menu::var<uint16_t> ainput_notch_filter_ai2{
    ainput_notch_filter_ai1
  };
  //! Отключение режекторного фильтра, AI3
  inline const menu::var<uint16_t> ainput_notch_filter_ai3{
    ainput_notch_filter_ai1
  };
  //! Отключение режекторного фильтра, AI4
  inline const menu::var<uint16_t> ainput_notch_filter_ai4{
    ainput_notch_filter_ai1
  };
  //! Отключение режекторного фильтра, AI5
  inline const menu::var<uint16_t> ainput_notch_filter_ai5{
    ainput_notch_filter_ai1
  };
  //! Отключение режекторного фильтра, AI6
  inline const menu::var<uint16_t> ainput_notch_filter_ai6{
    ainput_notch_filter_ai1
  };
  //! Отключение режекторного фильтра, AI7
  inline const menu::var<uint16_t> ainput_notch_filter_ai7{
    ainput_notch_filter_ai1
  };
  //! Отключение режекторного фильтра, AI8
  inline const menu::var<uint16_t> ainput_notch_filter_ai8{
    ainput_notch_filter_ai1
  };


  //! Значения параметра "Компенсация температуры холодного спая, AIx"
  struct AINPUT_JUNCTION
  {
    enum VALUE : uint16_t
    {
      DISABLED = 0, //!< Компенсация отключена
      AINPUT1  = 1, //!< Компенсация по аналоговому входу №1
      AINPUT2  = 2, //!< Компенсация по аналоговому входу №2
      AINPUT3  = 3, //!< Компенсация по аналоговому входу №3
      AINPUT4  = 4, //!< Компенсация по аналоговому входу №4
      AINPUT5  = 5, //!< Компенсация по аналоговому входу №5
      AINPUT6  = 6, //!< Компенсация по аналоговому входу №6
      AINPUT7  = 7, //!< Компенсация по аналоговому входу №7
      AINPUT8  = 8, //!< Компенсация по аналоговому входу №8
      INTERNAL = 9  //!< Компенсация со встроенного датчика
    };
  };

  //! Компенсация температуры холодного спая, AI1
  inline const menu::var<uint16_t> ainput_junction_ai1{{
    .default_value {AINPUT_JUNCTION::INTERNAL},
    .min_value     {AINPUT_JUNCTION::DISABLED},
    .max_value     {AINPUT_JUNCTION::INTERNAL}
  }};
  //! Компенсация температуры холодного спая, AI2
  inline const menu::var<uint16_t> ainput_junction_ai2{
    ainput_junction_ai1
  };
  //! Компенсация температуры холодного спая, AI3
  inline const menu::var<uint16_t> ainput_junction_ai3{
    ainput_junction_ai1
  };
  //! Компенсация температуры холодного спая, AI4
  inline const menu::var<uint16_t> ainput_junction_ai4{
    ainput_junction_ai1
  };
  //! Компенсация температуры холодного спая, AI5
  inline const menu::var<uint16_t> ainput_junction_ai5{
    ainput_junction_ai1
  };
  //! Компенсация температуры холодного спая, AI6
  inline const menu::var<uint16_t> ainput_junction_ai6{
    ainput_junction_ai1
  };
  //! Компенсация температуры холодного спая, AI7
  inline const menu::var<uint16_t> ainput_junction_ai7{
    ainput_junction_ai1
  };
  //! Компенсация температуры холодного спая, AI8
  inline const menu::var<uint16_t> ainput_junction_ai8{
    ainput_junction_ai1
  };


  /**
   * \brief Описание таблицы параметров "Настройка аналоговых входов"
   */
  inline const menu::TableInfo ainputs_table_info{
    ainput_type_ai1,
    ainput_type_ai2,
    ainput_type_ai3,
    ainput_type_ai4,
    ainput_type_ai5,
    ainput_type_ai6,
    ainput_type_ai7,
    ainput_type_ai8,
    ainput_filter_ai1,
    ainput_filter_ai2,
    ainput_filter_ai3,
    ainput_filter_ai4,
    ainput_filter_ai5,
    ainput_filter_ai6,
    ainput_filter_ai7,
    ainput_filter_ai8,
    ainput_normalize_low_ai1,
    ainput_normalize_low_ai2,
    ainput_normalize_low_ai3,
    ainput_normalize_low_ai4,
    ainput_normalize_low_ai5,
    ainput_normalize_low_ai6,
    ainput_normalize_low_ai7,
    ainput_normalize_low_ai8,
    ainput_normalize_high_ai1,
    ainput_normalize_high_ai2,
    ainput_normalize_high_ai3,
    ainput_normalize_high_ai4,
    ainput_normalize_high_ai5,
    ainput_normalize_high_ai6,
    ainput_normalize_high_ai7,
    ainput_normalize_high_ai8,
    ainput_level_low_ai1,
    ainput_level_low_ai2,
    ainput_level_low_ai3,
    ainput_level_low_ai4,
    ainput_level_low_ai5,
    ainput_level_low_ai6,
    ainput_level_low_ai7,
    ainput_level_low_ai8,
    ainput_level_high_ai1,
    ainput_level_high_ai2,
    ainput_level_high_ai3,
    ainput_level_high_ai4,
    ainput_level_high_ai5,
    ainput_level_high_ai6,
    ainput_level_high_ai7,
    ainput_level_high_ai8,
    ainput_alarm_low_ai1,
    ainput_alarm_low_ai2,
    ainput_alarm_low_ai3,
    ainput_alarm_low_ai4,
    ainput_alarm_low_ai5,
    ainput_alarm_low_ai6,
    ainput_alarm_low_ai7,
    ainput_alarm_low_ai8,
    ainput_alarm_high_ai1,
    ainput_alarm_high_ai2,
    ainput_alarm_high_ai3,
    ainput_alarm_high_ai4,
    ainput_alarm_high_ai5,
    ainput_alarm_high_ai6,
    ainput_alarm_high_ai7,
    ainput_alarm_high_ai8,
    ainput_slope_ai1,
    ainput_slope_ai2,
    ainput_slope_ai3,
    ainput_slope_ai4,
    ainput_slope_ai5,
    ainput_slope_ai6,
    ainput_slope_ai7,
    ainput_slope_ai8,
    ainput_shift_ai1,
    ainput_shift_ai2,
    ainput_shift_ai3,
    ainput_shift_ai4,
    ainput_shift_ai5,
    ainput_shift_ai6,
    ainput_shift_ai7,
    ainput_shift_ai8,
    ainput_decimal_ai1,
    ainput_decimal_ai2,
    ainput_decimal_ai3,
    ainput_decimal_ai4,
    ainput_decimal_ai5,
    ainput_decimal_ai6,
    ainput_decimal_ai7,
    ainput_decimal_ai8,
    ainput_notch_filter_ai1,
    ainput_notch_filter_ai2,
    ainput_notch_filter_ai3,
    ainput_notch_filter_ai4,
    ainput_notch_filter_ai5,
    ainput_notch_filter_ai6,
    ainput_notch_filter_ai7,
    ainput_notch_filter_ai8,
    ainput_junction_ai1,
    ainput_junction_ai2,
    ainput_junction_ai3,
    ainput_junction_ai4,
    ainput_junction_ai5,
    ainput_junction_ai6,
    ainput_junction_ai7,
    ainput_junction_ai8
  };


  /**
   * \brief Таблица параметров "Настройки аналоговых входов"
   */
  class AInputsTable : public decltype(menu::Table{ainputs_table_info})
  {
  public:
    using base_class = decltype(menu::Table{ainputs_table_info});
    using start_register =
      etl::integral_constant<uint16_t, REGISTERS::AINPUT_TYPE_AI1>;

    AInputsTable(elh::mutex* mutex=nullptr)
    : base_class{ainputs_table_info, mutex}
    {
    }
  };


  /**
   * \brief Описание таблицы параметров "Настройка аналоговых унифицированных 
   * входов"
   */
  inline const menu::TableInfo ainputs_u_table_info{
    ainput_type_u_ai1,
    ainput_type_u_ai2,
    ainput_type_u_ai3,
    ainput_type_u_ai4,
    ainput_type_u_ai5,
    ainput_type_u_ai6,
    ainput_type_u_ai7,
    ainput_type_u_ai8,
    ainput_filter_ai1,
    ainput_filter_ai2,
    ainput_filter_ai3,
    ainput_filter_ai4,
    ainput_filter_ai5,
    ainput_filter_ai6,
    ainput_filter_ai7,
    ainput_filter_ai8,
    ainput_normalize_low_ai1,
    ainput_normalize_low_ai2,
    ainput_normalize_low_ai3,
    ainput_normalize_low_ai4,
    ainput_normalize_low_ai5,
    ainput_normalize_low_ai6,
    ainput_normalize_low_ai7,
    ainput_normalize_low_ai8,
    ainput_normalize_high_ai1,
    ainput_normalize_high_ai2,
    ainput_normalize_high_ai3,
    ainput_normalize_high_ai4,
    ainput_normalize_high_ai5,
    ainput_normalize_high_ai6,
    ainput_normalize_high_ai7,
    ainput_normalize_high_ai8,
    ainput_level_low_ai1,
    ainput_level_low_ai2,
    ainput_level_low_ai3,
    ainput_level_low_ai4,
    ainput_level_low_ai5,
    ainput_level_low_ai6,
    ainput_level_low_ai7,
    ainput_level_low_ai8,
    ainput_level_high_ai1,
    ainput_level_high_ai2,
    ainput_level_high_ai3,
    ainput_level_high_ai4,
    ainput_level_high_ai5,
    ainput_level_high_ai6,
    ainput_level_high_ai7,
    ainput_level_high_ai8,
    ainput_alarm_low_ai1,
    ainput_alarm_low_ai2,
    ainput_alarm_low_ai3,
    ainput_alarm_low_ai4,
    ainput_alarm_low_ai5,
    ainput_alarm_low_ai6,
    ainput_alarm_low_ai7,
    ainput_alarm_low_ai8,
    ainput_alarm_high_ai1,
    ainput_alarm_high_ai2,
    ainput_alarm_high_ai3,
    ainput_alarm_high_ai4,
    ainput_alarm_high_ai5,
    ainput_alarm_high_ai6,
    ainput_alarm_high_ai7,
    ainput_alarm_high_ai8,
    ainput_slope_ai1,
    ainput_slope_ai2,
    ainput_slope_ai3,
    ainput_slope_ai4,
    ainput_slope_ai5,
    ainput_slope_ai6,
    ainput_slope_ai7,
    ainput_slope_ai8,
    ainput_shift_ai1,
    ainput_shift_ai2,
    ainput_shift_ai3,
    ainput_shift_ai4,
    ainput_shift_ai5,
    ainput_shift_ai6,
    ainput_shift_ai7,
    ainput_shift_ai8,
    ainput_notch_filter_ai1,
    ainput_notch_filter_ai2,
    ainput_notch_filter_ai3,
    ainput_notch_filter_ai4,
    ainput_notch_filter_ai5,
    ainput_notch_filter_ai6,
    ainput_notch_filter_ai7,
    ainput_notch_filter_ai8,
    ainput_decimal_ai1,
    ainput_decimal_ai2,
    ainput_decimal_ai3,
    ainput_decimal_ai4,
    ainput_decimal_ai5,
    ainput_decimal_ai6,
    ainput_decimal_ai7,
    ainput_decimal_ai8
  };


  /**
   * \brief Таблица параметров "Настройки аналоговых унифицированных входов"
   */
  class AInputsU_Table : public decltype(menu::Table{ainputs_u_table_info})
  {
  public:
    using base_class = decltype(menu::Table{ainputs_u_table_info});
    using start_register =
      etl::integral_constant<uint16_t, REGISTERS::AINPUT_TYPE_AI1>;

    AInputsU_Table(elh::mutex* mutex=nullptr)
    : base_class{ainputs_u_table_info, mutex}
    {
    }
  };


  /**
   * \brief Описание таблицы параметров "Настройка аналоговых температурных 
   * входов"
   */
  inline const menu::TableInfo ainputs_t_table_info{
    ainput_type_t_ai1,
    ainput_type_t_ai2,
    ainput_type_t_ai3,
    ainput_type_t_ai4,
    ainput_type_t_ai5,
    ainput_type_t_ai6,
    ainput_type_t_ai7,
    ainput_type_t_ai8,
    ainput_filter_ai1,
    ainput_filter_ai2,
    ainput_filter_ai3,
    ainput_filter_ai4,
    ainput_filter_ai5,
    ainput_filter_ai6,
    ainput_filter_ai7,
    ainput_filter_ai8,
    ainput_normalize_low_ai1,
    ainput_normalize_low_ai2,
    ainput_normalize_low_ai3,
    ainput_normalize_low_ai4,
    ainput_normalize_low_ai5,
    ainput_normalize_low_ai6,
    ainput_normalize_low_ai7,
    ainput_normalize_low_ai8,
    ainput_normalize_high_ai1,
    ainput_normalize_high_ai2,
    ainput_normalize_high_ai3,
    ainput_normalize_high_ai4,
    ainput_normalize_high_ai5,
    ainput_normalize_high_ai6,
    ainput_normalize_high_ai7,
    ainput_normalize_high_ai8,
    ainput_level_low_ai1,
    ainput_level_low_ai2,
    ainput_level_low_ai3,
    ainput_level_low_ai4,
    ainput_level_low_ai5,
    ainput_level_low_ai6,
    ainput_level_low_ai7,
    ainput_level_low_ai8,
    ainput_level_high_ai1,
    ainput_level_high_ai2,
    ainput_level_high_ai3,
    ainput_level_high_ai4,
    ainput_level_high_ai5,
    ainput_level_high_ai6,
    ainput_level_high_ai7,
    ainput_level_high_ai8,
    ainput_alarm_low_ai1,
    ainput_alarm_low_ai2,
    ainput_alarm_low_ai3,
    ainput_alarm_low_ai4,
    ainput_alarm_low_ai5,
    ainput_alarm_low_ai6,
    ainput_alarm_low_ai7,
    ainput_alarm_low_ai8,
    ainput_alarm_high_ai1,
    ainput_alarm_high_ai2,
    ainput_alarm_high_ai3,
    ainput_alarm_high_ai4,
    ainput_alarm_high_ai5,
    ainput_alarm_high_ai6,
    ainput_alarm_high_ai7,
    ainput_alarm_high_ai8,
    ainput_slope_ai1,
    ainput_slope_ai2,
    ainput_slope_ai3,
    ainput_slope_ai4,
    ainput_slope_ai5,
    ainput_slope_ai6,
    ainput_slope_ai7,
    ainput_slope_ai8,
    ainput_shift_ai1,
    ainput_shift_ai2,
    ainput_shift_ai3,
    ainput_shift_ai4,
    ainput_shift_ai5,
    ainput_shift_ai6,
    ainput_shift_ai7,
    ainput_shift_ai8,
    ainput_decimal_ai1,
    ainput_decimal_ai2,
    ainput_decimal_ai3,
    ainput_decimal_ai4,
    ainput_decimal_ai5,
    ainput_decimal_ai6,
    ainput_decimal_ai7,
    ainput_decimal_ai8,
    ainput_notch_filter_ai1,
    ainput_notch_filter_ai2,
    ainput_notch_filter_ai3,
    ainput_notch_filter_ai4,
    ainput_notch_filter_ai5,
    ainput_notch_filter_ai6,
    ainput_notch_filter_ai7,
    ainput_notch_filter_ai8,
    ainput_junction_ai1,
    ainput_junction_ai2,
    ainput_junction_ai3,
    ainput_junction_ai4,
    ainput_junction_ai5,
    ainput_junction_ai6,
    ainput_junction_ai7,
    ainput_junction_ai8
  };


  /**
   * \brief Таблица параметров "Настройки аналоговых температурных входов"
   */
  class AInputsT_Table : public decltype(menu::Table{ainputs_t_table_info})
  {
  public:
    using base_class = decltype(menu::Table{ainputs_t_table_info});
    using start_register =
      etl::integral_constant<uint16_t, REGISTERS::AINPUT_TYPE_AI1>;

    AInputsT_Table(elh::mutex* mutex=nullptr)
    : base_class{ainputs_t_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_ainputs
   */

  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_aoutputs Настройки аналоговых выходов
   * \{
   */

  //! Значения параметра "Тип выходного сигнала"
  struct AOUTPUT_TYPE
  {
    enum VALUE : uint16_t
    {
      UNIFIED_0_20_MA = 0, //!< 0...20 мА (0 → 100%)
      UNIFIED_4_20_MA = 1, //!< 4...20 мА (0 → 100%)
      UNIFIED_0_10_V  = 2, //!< 0...10 В  (0 → 100%)
      UNIFIED_20_0_MA = 3, //!< 0...20 мА (100 → 0%)
      UNIFIED_20_4_MA = 4, //!< 4...20 мА (100 → 0%)
      UNIFIED_10_0_V  = 5  //!< 0...10 В  (100 → 0%)
    };
  };

  //! Тип выходного сигнала, выход 1
  inline const menu::var<uint16_t> aoutput_type_ao1{{
    .default_value {AOUTPUT_TYPE::UNIFIED_0_20_MA},
    .min_value     {AOUTPUT_TYPE::UNIFIED_0_20_MA},
    .max_value     {AOUTPUT_TYPE::UNIFIED_10_0_V}
  }};
  //! Тип выходного сигнала, выход 2
  inline const menu::var<uint16_t> aoutput_type_ao2{
    aoutput_type_ao1
  };
  //! Тип выходного сигнала, выход 3
  inline const menu::var<uint16_t> aoutput_type_ao3{
    aoutput_type_ao1
  };
  //! Тип выходного сигнала, выход 4
  inline const menu::var<uint16_t> aoutput_type_ao4{
    aoutput_type_ao1
  };


  //! Нижний предел нормализации аналогового выхода AO1
  inline const menu::var<int16_t> aoutput_normalize_low_ao1{{
    .default_value {0},
    .min_value     {-100},
    .max_value     {10100}
  }};
  //! Нижний предел нормализации аналогового выхода AO2
  inline const menu::var<int16_t> aoutput_normalize_low_ao2{
    aoutput_normalize_low_ao1
  };
  //! Нижний предел нормализации аналогового выхода AO3
  inline const menu::var<int16_t> aoutput_normalize_low_ao3{
    aoutput_normalize_low_ao1
  };
  //! Нижний предел нормализации аналогового выхода AO4
  inline const menu::var<int16_t> aoutput_normalize_low_ao4{
    aoutput_normalize_low_ao1
  };


  //! Верхний предел нормализации аналогового выхода AO1
  inline const menu::var<int16_t> aoutput_normalize_high_ao1{{
    .default_value {10000},
    .min_value     {-100},
    .max_value     {10100}
  }};
  //! Верхний предел нормализации аналогового выхода AO2
  inline const menu::var<int16_t> aoutput_normalize_high_ao2{
    aoutput_normalize_high_ao1
  };
  //! Верхний предел нормализации аналогового выхода AO3
  inline const menu::var<int16_t> aoutput_normalize_high_ao3{
    aoutput_normalize_high_ao1
  };
  //! Верхний предел нормализации аналогового выхода AO4
  inline const menu::var<int16_t> aoutput_normalize_high_ao4{
    aoutput_normalize_high_ao1
  };


  //! Безопасное значение аналогового выхода AO1
  inline const menu::var<int16_t> aoutput_safe_value_ao1{{
    .default_value {0},
    .min_value     {-1000},
    .max_value     {11000}
  }};
  //! Безопасное значение аналогового выхода AO2
  inline const menu::var<int16_t> aoutput_safe_value_ao2{
    aoutput_safe_value_ao1
  };
  //! Безопасное значение аналогового выхода AO3
  inline const menu::var<int16_t> aoutput_safe_value_ao3{
    aoutput_safe_value_ao1
  };
  //! Безопасное значение аналогового выхода AO4
  inline const menu::var<int16_t> aoutput_safe_value_ao4{
    aoutput_safe_value_ao1
  };


  /**
   * \brief Задержка перехода выходов в безопасное состояние, x * с
   * \details
   * Значение "0" - функция отключена
   */
  inline const menu::var<uint16_t> aoutput_safe_state_delay{{
    .default_value {0},
    .min_value     {0},
    .max_value     {65535}
  }};


  /**
   * \brief Описание таблицы параметров "Настройки аналоговых выходов"
   */
  inline const menu::TableInfo aoutputs_table_info{
    aoutput_type_ao1,
    aoutput_type_ao2,
    aoutput_type_ao3,
    aoutput_type_ao4,
    aoutput_normalize_low_ao1,
    aoutput_normalize_low_ao2,
    aoutput_normalize_low_ao3,
    aoutput_normalize_low_ao4,
    aoutput_normalize_high_ao1,
    aoutput_normalize_high_ao2,
    aoutput_normalize_high_ao3,
    aoutput_normalize_high_ao4,
    aoutput_safe_value_ao1,
    aoutput_safe_value_ao2,
    aoutput_safe_value_ao3,
    aoutput_safe_value_ao4,
    aoutput_safe_state_delay
  };


  /**
   * \brief Таблица параметров "Настройки аналоговых выходов"
   */
  class AOutputsTable : public decltype(menu::Table{aoutputs_table_info})
  {
  public:
    using base_class = decltype(menu::Table{aoutputs_table_info});
    using start_register =
      etl::integral_constant<uint16_t, REGISTERS::AOUTPUT_TYPE_AO1>;

    AOutputsTable(elh::mutex* mutex=nullptr)
    : base_class{aoutputs_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_aoutputs
   */

  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_modbus Настройки Modbus
   * \{
   */

  //! Modbus-адрес устройства
  inline const menu::var<uint16_t> modbus_address{{
    .default_value {1},
    .min_value     {1},
    .max_value     {247}
  }};


  //! Значения параметра "Скорость обмена по интерфейсу"
  struct MODBUS_BAUDRATE
  {
    enum VALUE
    {
      R2400   = 0,  //!< 2400 бит/с
      R4800   = 1,  //!< 4800 бит/с
      R9600   = 2,  //!< 9600 бит/с
      R14400  = 3,  //!< 14400 бит/с
      R19200  = 4,  //!< 19200 бит/с
      R28800  = 5,  //!< 28800 бит/с
      R38400  = 6,  //!< 38400 бит/с
      R57600  = 7,  //!< 57600 бит/с
      R76800  = 8,  //!< 76800 бит/с
      R115200 = 9,  //!< 115200 бит/с
      R128000 = 10, //!< 128000 бит/с
      R256000 = 11  //!< 256000 бит/с
    };
  };

  //! Скорость обмена по интерфейсу
  inline const menu::var<uint16_t> modbus_baudrate{{
    .default_value {MODBUS_BAUDRATE::R115200},
    .min_value     {MODBUS_BAUDRATE::R2400},
    .max_value     {MODBUS_BAUDRATE::R256000}
  }};


  //! Значения параметра "Контроль четности"
  struct MODBUS_PARITY
  {
    enum VALUE
    {
      NONE = 0, //!< Нет
      EVEN = 1, //!< Четный
      ODD  = 2  //!< Нечетный
    };
  };

  //! Контроль четности
  inline const menu::var<uint16_t> modbus_parity{{
    .default_value {MODBUS_PARITY::NONE},
    .min_value     {MODBUS_PARITY::NONE},
    .max_value     {MODBUS_PARITY::EVEN}
  }};


  //! Стоп-биты
  inline const menu::var<uint16_t> modbus_stop_bits{{
    .default_value {1},
    .min_value     {1},
    .max_value     {2}
  }};

  //! Задержка ответа по интерфейсу, x * мс
  inline const menu::var<uint16_t> modbus_delay{{
    .default_value {20},
    .min_value     {0},
    .max_value     {500}
  }};


  //! Значения параметра "Применение и сохранение настроек Modbus"
  struct MODBUS_SAVE_SETTINGS
  {
    enum VALUE
    {
      NONE      = 0, //!< Нет действия
      TEMPORARY = 1, //!< Применение без сохранения в Flash-память 
      EEPROM    = 2  //!< Применение и сохранение в Flash-память
    };
  };

  //! Применение и сохранение настроек Modbus
  inline const menu::var<uint16_t> modbus_save_settings{{
    .default_value {MODBUS_SAVE_SETTINGS::NONE},
    .min_value     {MODBUS_SAVE_SETTINGS::NONE},
    .max_value     {MODBUS_SAVE_SETTINGS::EEPROM}
  }};


  /**
   * \brief Описание таблицы параметров "Настройки Modbus"
   */
  inline const menu::TableInfo modbus_table_info{
    modbus_address,
    modbus_baudrate,
    modbus_parity,
    modbus_stop_bits,
    modbus_delay,
    modbus_save_settings
  };


  /**
   * \brief Таблица параметров "Настройки Modbus"
   */
  class ModbusTable : public decltype(menu::Table{modbus_table_info})
  {
  public:
    using base_class = decltype(menu::Table{modbus_table_info});
    using start_register = 
      etl::integral_constant<uint16_t, REGISTERS::MODBUS_ADDRESS>;

    ModbusTable(elh::mutex* mutex=nullptr)
    : base_class{modbus_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_modbus
   */

  /**
   * \addtogroup modbus_devices_elhart_alphax_parameter_save Сохранение параметров в энергонезависимую память
   * \{
   */

    //! Значения параметра "Внутренняя ошибка модуля"
  struct INTERNAL_ERROR
  {
    enum BITMASK : uint16_t
    {
      NONE       = 0x00, //!< Нет ошибок
      MODBUS     = 0x01, //!< Ошибка связи Modbus
      SAVE       = 0x02, //!< Ошибка сохранения параметров
      RESTORED   = 0x04, //!< Восстановлены старые значения параметров
      ADJUSTMENT = 0x08, //!< Ошибка юстировочных коэффициентов
      ADC        = 0x10, //!< Ошибка АЦП
      CORRECTION = 0x20, //!< Ошибка температурной коррекции аналогового входа
      JUNCTION   = 0x40, //!< Ошибка датчика температуры холодного спая
      ALL        = 0x3F  //!< Маска всех ошибок
    };
  };

  //! Внутренняя ошибка модуля
  inline const menu::var<uint16_t> internal_error{{
    .default_value {INTERNAL_ERROR::NONE},
    .min_value     {INTERNAL_ERROR::NONE},
    .max_value     {INTERNAL_ERROR::ALL}
  }};


  //! Значения параметра "Сохранение всех настроек во Flash-память"
  struct SAVE_SETTINGS
  {
    enum VALUE : uint16_t
    {
      NONE                   = 0, //!< Нет действия
      SAVE                   = 1, //!< Сохранение без применения настроек Modbus
      SAVE_AND_CONFIG_MODBUS = 2  //!< Сохранение и применение настроек Modbus
    };
  };

  //! Сохранение всех настроек во Flash-память
  inline const menu::var<uint16_t> save_settings{{
    .default_value {SAVE_SETTINGS::NONE},
    .min_value     {SAVE_SETTINGS::NONE},
    .max_value     {SAVE_SETTINGS::SAVE_AND_CONFIG_MODBUS}
  }};


  //! Значения параметра "Сброс настроек на заводские параметры"
  struct FACTORY_RESET
  {
    enum VALUE : uint16_t
    {
      NONE      = 0, //!< Нет действия
      NO_MODBUS = 1, //!< Сброс всех настроек, кроме настроек Modbus
      ALL       = 2  //!< Сброс всех настроек
    };
  };

  //! Сброс настроек на заводские параметры
  inline const menu::var<uint16_t> factory_reset{{
    .default_value {FACTORY_RESET::NONE},
    .min_value     {FACTORY_RESET::NO_MODBUS},
    .max_value     {FACTORY_RESET::ALL}
  }};


  /**
   * \brief Описание таблицы параметров "Сохранение параметров 
   * в энергонезависимую память"
   */
  inline const menu::TableInfo save_table_info{
    internal_error,
    save_settings,
    factory_reset
  };


  /**
   * \brief Таблица параметров "Сохранение параметров"
   */
  class SaveTable : public decltype(menu::Table{save_table_info})
  {
  public:
    using base_class = decltype(menu::Table{save_table_info});
    using start_register =
      etl::integral_constant<uint16_t, REGISTERS::INTERNAL_ERROR>;

    SaveTable(elh::mutex* mutex=nullptr)
    : base_class{save_table_info, mutex}
    {
    }
  };

  /**
   * \}
   * \noop modbus_devices_elhart_alphax_parameter_save
   */
}
