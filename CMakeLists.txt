cmake_minimum_required(VERSION 2.8)

project(brainfuck_cpp)

add_executable(brainfuck_cpp main.cpp)

target_include_directories(brainfuck_cpp PUBLIC src/)
