cmake_minimum_required(VERSION 3.25)

project(HarshiMart LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HarshiMart
    src/main.cpp
    repositories/ProductRepository.cpp
)

target_include_directories(HarshiMart PRIVATE
    "C:/msys64/ucrt64/include"
)

target_link_directories(HarshiMart PRIVATE
    "C:/msys64/ucrt64/lib"
)

target_link_libraries(HarshiMart PRIVATE
    ws2_32
    sqlite3
)
