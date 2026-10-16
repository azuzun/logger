cmake_minimum_required(VERSION 3.16)

project(console_input_logger VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(console_input_logger src/main.cpp)
target_link_libraries(console_input_logger PRIVATE Threads::Threads)

add_executable(ofstream_example examples/ofstream_example.cpp)

include(CTest)
if(BUILD_TESTING)
    add_test(NAME ofstream_example_smoke COMMAND ofstream_example)
endif()
