/**
 * \file modbus/devices/elhart/elhart_device.h
 * \brief Общий класс устройств ЭЛХАРТ с протоколом связи Modbus
 */

#pragma once

#include "modbus/modbus_device.h"


namespace modbus::devices::elhart
{
  /**
   * \brief Описание модификации устройств ЭЛХАРТ
   */
  struct DeviceModificationInfo
  {
    const etl::string_view name_v;         //!< Название устройства
    const etl::string_view modification_v; //!< Код модификации устройства
    const uint8_t  discrete_inputs_v;      //!< Кол-во дискретных входов
    const uint8_t  discrete_outputs_v;     //!< Кол-во дискретных выходов
    const uint8_t  analog_inputs_v;        //!< Кол-во аналоговых входов
    const uint8_t  analog_outputs_v;       //!< Кол-во аналоговых выходов
  };


  /**
   * \brief Устройство ЭЛХАРТ с протоколом связи Modbus
   */
  class ElhartDevice : public Device
  {
  public:
    //! Дополнительные состояния устройств ЭЛХАРТ
    enum STATE : uint8_t
    {
      STATE_READ_MODIFICATION = device::iDevice::STATE_SIZE,
      STATE_READ_VERSION,
      STATE_READ_SERIAL_NUMBER
    };


    /**
     * \brief Конструктор устройства ЭЛХАРТ
     */
    ElhartDevice(const Init& init)
    : Device{init},
      _setup_poll_channel{{
        {
          .tree       {_setup_tree},
          .auto_write {false}
        },
        .address        {init.address},
        .function_write {0x10},
        .function_read  {0x03}
      }}
    {
    }

    device::PollChannel* init(menu::iTableNode* init_node) override;
    void update() override;

  protected:
    etl::string<5> _modification;  //!< Строка с кодом модификации устройства
    etl::string<5> _serial_number; //!< Строка с серийным номером устройства
    ModbusTree<1>     _setup_tree {menu::iTableTree::dummy_node};
    ModbusPollChannel _setup_poll_channel;
  };


  /**
   * \brief Создает массив со списком модификаций приборов ЭЛХАРТ
   */
  template<typename... T>
  constexpr auto MakeDeviceModificationInfoArray()
    -> etl::array<DeviceModificationInfo, sizeof...(T)>
  {
    return {{
      etl::forward<DeviceModificationInfo>({
        .name_v             {T::name},
        .modification_v     {T::modification},
        .discrete_inputs_v  {T::discrete_inputs::value},
        .discrete_outputs_v {T::discrete_outputs::value},
        .analog_inputs_v    {T::analog_inputs::value},
        .analog_outputs_v   {T::analog_outputs::value}
      })...
    }};
  }
}
