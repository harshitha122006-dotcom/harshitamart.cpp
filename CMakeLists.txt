cmake_minimum_required(VERSION 3.25)

project(HarshiMart)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HarshiMart
    src/main.cpp
    repositories/ProductRepository.cpp
)

target_link_libraries(HarshiMart PRIVATE ws2_32)