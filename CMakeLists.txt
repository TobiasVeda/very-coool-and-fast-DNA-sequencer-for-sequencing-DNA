cmake_minimum_required(VERSION 4.3)
project(very_coool_and_fast_DNA_sequencer_for_sequencing_DNA)

set(CMAKE_CXX_STANDARD 20)

add_executable(very_coool_and_fast_DNA_sequencer_for_sequencing_DNA main.cpp
        KPM_matcher.cpp
        KPM_matcher.h
        very_bad_and_slow_string_compare.cpp)
