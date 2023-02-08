cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_os C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK
pico_sdk_init()

# Main project artifacts
add_executable(pico_os src/main.c)

target_sources(pico_os PRIVATE src/home.c src/home.h)

# pull in common dependencies
target_link_libraries(pico_os pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(pico_os 1)
pico_enable_stdio_uart(pico_os 1)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(pico_os)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )