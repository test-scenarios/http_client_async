cmake_minimum_required( VERSION 3.17.3 )
include (cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.261.tar.gz"
        SHA1 "1540dad7b97c849784a09e8c452ba811c9f71ba2"
)
project(http2 VERSION 1.0)

hunter_add_package(Boost COMPONENTS system)
hunter_add_package(OpenSSL)

find_package(Boost CONFIG COMPONENTS system)
find_package(OpenSSL)
find_package(Threads)


#set(CMAKE_CXX_STANDARD 17)

#set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_PATH "/opt/dev/f32/boost/1.73.0")

add_executable(http_client_async main.cpp session.hpp)
target_link_libraries(http_client_async PRIVATE Boost::system OpenSSL::Crypto OpenSSL::SSL Threads::Threads)

#include_directories(${Boost_PATH}/include)
#target_link_libraries(http_client_async
#  ${Boost_PATH}/lib/libboost_system.a
#  ${Boost_PATH}/lib/libboost_thread.a
#  pthread)
