cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  MESSAGE(FATAL_ERROR "Do not build in source directory.")
endif()

set(Boost_ADDITIONAL_VERSIONS "1.49" "1.49.0")
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package( Boost 1.49.0 REQUIRED COMPONENTS thread date_time)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(boost_thread_test boost_thread_test.cpp)
target_link_libraries(boost_thread_test ${Boost_LIBRARIES})
