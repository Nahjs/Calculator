cmake_minimum_required(VERSION 3.29)
project(Caculator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Caculator
        main.cpp
        calculator.cpp
        calculator.h
        Calculator.ui
)

target_link_libraries(Caculator
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)