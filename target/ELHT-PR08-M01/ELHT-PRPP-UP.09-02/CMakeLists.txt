# Таргет Alpha-X CPU
project(AXCode_CPU_target
        LANGUAGES C CXX ASM
        DESCRIPTION "Таргет для компиляции пользовательской программы AXCode в целевом процессорном модуле"
        VERSION 1.1.3
        )

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
target_link_libraries(${PROJECT_NAME} INTERFACE
  AXCode_CPU_kernel
  plc
  kernel
  Modbus
  Devices
  time_menu
  terminal
  Menu
  freertos_kernel
  freertos_kernel_port
  kernel
  mcu
  mcu_port_riscv_wch_ch32v30x_lib
  common
)
