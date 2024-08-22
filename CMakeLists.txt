cmake_minimum_required(VERSION 3.10)

project(Alchemist-N)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp gamewindow.cpp menuwindow.cpp statuswindow.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(main ${CURSES_LIBRARIES})