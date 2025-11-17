cmake_minimum_required(VERSION 3.10)
project(bgp_simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(bgp_simulator
    src/main.cpp
    src/AS.cpp
    src/Announcement.cpp
    src/BGP.cpp
    src/ROV.cpp
    src/Graph.cpp
    src/Parser.cpp 
    src/Propagation.cpp
)

target_include_directories(bgp_simulator PUBLIC src)
