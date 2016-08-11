cmake_minimum_required(VERSION 3.6)
set(CURL_MIN_VERSION "7.28.0")

project(cpp_scratchpad)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    push.cpp cxxopts.hpp)

#set directories
include_directories(/usr/local/include/curlpp)
link_directories(/usr/local/include/curlpp)

add_executable(cpp_scratchpad ${SOURCE_FILES})


#link curl and curlcpp
target_link_libraries(cpp_scratchpad curlpp.a curl)
