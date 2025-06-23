cmake_minimum_required(VERSION 3.10)
project(mtb_builder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(mtb_cli
    src/main.cpp
    src/db.cpp
)

target_link_libraries(mtb_cli sqlite3)

