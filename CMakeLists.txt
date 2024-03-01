cmake_minimum_required(VERSION 3.5)

option(BUILD_TEST "Build test" OFF)

project(pr_log)

# pr_log
add_library(pr_log STATIC pr_log.c pr_log_extern.c)
target_include_directories(pr_log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
if (BUILD_TEST)
    add_subdirectory(test)
endif ()
