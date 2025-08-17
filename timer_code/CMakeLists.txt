# Find Zephyr. This also loads Zephyr's build system.
cmake_minimum_required(VERSION 3.26.3)
if(NOT DEFINED BOARD)
  set(BOARD oxycontroller4_samd21)
endif()
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(my_zephyr_app)

# Show the info about our project
message("Project: ${PROJECT_NAME}")
message("Board: ${BOARD}")


zephyr_compile_options(-U_FORTIFY_SOURCE)

target_sources(app PRIVATE
    src/main.c)
