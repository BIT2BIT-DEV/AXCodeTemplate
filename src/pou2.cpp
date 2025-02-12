/**
 * \file pou2.cpp
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


void POU2()
{
  static bool init = false;
  if (!init)
  {
    init = true;
    // Инициализация переменных данной POU
    // Код в этом блоке выполнится 1 раз

  }

  print_debug("Second stage\r\n");

  // Код, выполняемый циклически:
  
}
