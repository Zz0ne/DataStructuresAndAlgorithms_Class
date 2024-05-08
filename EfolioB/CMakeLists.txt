cmake_minimum_required(VERSION 3.21.7)

project(EFolioB)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -g -g3")

include_directories(include)

set(SOURCE_FILES src/main.cpp src/maxh.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
