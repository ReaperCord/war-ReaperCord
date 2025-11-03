cmake_minimum_required(VERSION 4.0)
project(war_ReaperCord C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(war_ReaperCord
        war-iniciante.c
        war.c)
