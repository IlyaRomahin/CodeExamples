cmake_minimum_required(VERSION 3.12)
project(network)

set(CMAKE_CXX_STANDARD 17)

list(APPEND includePath "${CMAKE_CURRENT_LIST_DIR}//..//Network3//Socket")

add_executable(network main.cpp "${includePath}//MySocket.cpp" ReplicateCounter.cpp ReplicateCounter.h)
add_executable(test test.cpp "${includePath}//MySocket.cpp" ReplicateCounter.cpp ReplicateCounter.h)
if (WIN32)
    target_link_libraries(network  ws2_32)
else()
    target_link_libraries(network pthread)
endif()
target_include_directories(network PUBLIC "$<BUILD_INTERFACE:${includePath}>")
target_include_directories(test PUBLIC "$<BUILD_INTERFACE:${includePath}>")
