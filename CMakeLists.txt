cmake_minimum_required(VERSION 3.5)

project(pr_log)

# pr_log
add_library(pr_log STATIC pr_log.c)
target_include_directories(pr_log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)
