cmake_minimum_required(VERSION 3.5)

project(Chess-Engine)

# Add the executable target
add_executable(test
    Bitboard.hpp
    Bitboard.cpp
    Gamestate.hpp
    Gamestate.cpp
    Test.cpp
)

# Specify C++ standard
target_compile_features(test PRIVATE cxx_std_20)
