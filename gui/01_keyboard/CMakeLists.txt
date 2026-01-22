cmake_minimum_required(VERSION 3.5)
project(01_keyboard)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5Widgets REQUIRED)

# Enable automatic moc
set(CMAKE_AUTOMOC ON)

# later on, we'll use Qt Creator to build out our UI
# Qt Creator creates .ui files which will be preprocessed for us (that's what qt5_wrap_ui does)
# After preprocessing, a .h and .cpp file are produced for each .ui file
# we add the binary output directory as an include directory so that we can include the .h file later on
file(GLOB example_UIS *.ui)
qt5_wrap_ui(example_UIS ${example_UIS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(VirtualKeyboard
    main.cpp
    KeyboardWidget.cpp
    KeyboardWidget.h
)

target_link_libraries(VirtualKeyboard
    Qt5::Widgets
)
