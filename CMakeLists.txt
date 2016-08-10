cmake_minimum_required(VERSION 2.8)
set(CURL_MIN_VERSION "7.28.0")

# Setting up project
project(scratchpad.app)

#set c++ flags
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++14")

#set directories
include_directories(/usr/local/include/curlpp)
link_directories(/usr/local/include/curlpp)

add_executable(scratchpad.app
push.cpp
)

#link curl and curlcpp
target_link_libraries(scratchpad.app curlpp.a curl)
