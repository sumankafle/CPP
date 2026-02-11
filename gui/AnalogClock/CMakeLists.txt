cmake_minimum_required(VERSION 3.5)
project(analogclock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Qt automatic tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Collect sources (only .cpp, moc handles headers via AUTOMOC)
file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

add_executable(analogclock ${SRC_FILES})

target_include_directories(analogclock PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(analogclock Qt5::Widgets)
