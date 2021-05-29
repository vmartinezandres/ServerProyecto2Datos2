cmake_minimum_required(VERSION 3.19)
project(Backend)

set(CMAKE_CXX_STANDARD 14)

add_executable(Backend main.cpp src/server.cpp include/server.h src/bPGameServer.cpp include/bPGameServer.h src/geneticPuzzleServer.cpp include/geneticPuzzleServer.h)