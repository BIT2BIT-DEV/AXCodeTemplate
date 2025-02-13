/**
 * \file pou1.cpp
 * \brief Файл пользовательской POU
 * \details
 * Файл должен включать строки
 * \code{.cpp}
 * #include "pou_manager.h"
 * using namespace plc;
 * \endcode
 * для доступа ко всем функциям программируемого контроллера
 */

#include "pou_manager.h"

using namespace plc;

  DiscreteOutputArray<2> DO (cpu_io);

  ModbusBuffer<1520> buffer;

  ModbusMaster modbus_master ({
    // Номер COM-порта
    .com              = COM1,
    // Список устройств для автоматического опроса
    .devices          = {},
    // Скорость обмена, бит/с
    .baudrate         = 115200,
    // Четность
    .parity           = COM_PARITY_NONE,
    // Кол-во стоп-битов
    .stop_bits        = 1,
    // Пауза перед отправкой команды опроса (мс)
    .poll_delay       = 10,
    // Пауза после отправки широковещательного запроса (мс)
    .turnaround_delay = 100,
    // Время ожидания ответа (мс)
    .response_timeout = 300,
    // Количество попыток связи
    .failed_attempts  = 3,
    // Время восстановления опроса (мс)
    .restore_timeout  = 3000
  });
  
  uint32_t i = 0;

  void delay(uint32_t ms)
  {
    uint32_t set_t = GetSysTicks();
    while ((GetSysTicks() - set_t) < ms){print_event("delay...(%d)\r\n", GetSysTicks() - set_t);}
  }

void POU1()
{
  static bool init = false;
  if (!init)
  {
    init = true;
    // Инициализация переменных данной POU
    // Код в этом блоке выполнится 1 раз
    DO[0] = true;
    DO[1] = false;
  }

  // Код, выполняемый циклически:
  print_debug("Baudrate %d\t Address %d\n\r", modbus_master.baudrate, modbus_master.poll_delay);
  print_debug("GetSysTicks %d.%d s\n\r", GetSysTicks()/1000, GetSysTicks()%1000);
  print_debug(RTC.getTimeString());
  print_debug("\r\n\r\n");
  
  DO[1] = DO[0].value();
  DO[0] = !DO[1].value();
  
}
