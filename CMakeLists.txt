cmake_minimum_required(VERSION 3.17)
project(gather_windows C)

set(CMAKE_C_STANDARD 99)

add_executable(gather_windows main.c)

target_link_libraries(gather_windows
          "-framework CoreGraphics"
          "-framework Foundation"
          )

