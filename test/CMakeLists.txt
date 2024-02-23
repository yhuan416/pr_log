add_executable(demo main.c mod1.c)

target_link_libraries(demo pr_log)

add_test(NAME demo COMMAND $<TARGET_FILE:demo>)
