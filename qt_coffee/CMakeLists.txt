cmake_minimum_required(VERSION 3.5)
project(qt_coffee LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Enable automoc/autoresources for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# include directory for headers


file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Explicitly wrap headers that use Q_OBJECT to ensure moc generation
set(MOC_HEADERS
    ${CMAKE_SOURCE_DIR}/include/mainwindow.h
)
qt5_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})

add_executable(qt_coffee ${SRC_FILES} ${MOC_SOURCES})
target_include_directories(qt_coffee PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(qt_coffee Qt5::Widgets)
