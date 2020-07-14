cmake_minimum_required( VERSION 3.17.3 )
project(http2 VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_PATH "/opt/dev/f32/boost/1.73.0")

add_executable(http_client_async main.cpp session.hpp)
include_directories(${Boost_PATH}/include)
target_link_libraries(http_client_async
  ${Boost_PATH}/lib/libboost_system.a
  ${Boost_PATH}/lib/libboost_thread.a
  pthread)
