cmake_minimum_required(VERSION 3.9)

project(event_broker VERSION 1.0.0 DESCRIPTION "your bright idea goes here")

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SRC_DIR}/modules/")

include_directories (
    $ENV{PROJECT_SRC_DIR}
)

add_definitions(-DBOOST_LOG_DYN_LINK)

# compiler flags
set (CMAKE_CXX_FLAGS    "-Wall -ggdb -std=c++17")

# Target
add_subdirectory(src)
