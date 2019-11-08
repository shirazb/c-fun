add_executable(test_list_node test_list_node.c)

target_compile_features(test_list_node PRIVATE c_std_11)

if(MSVC)
  target_compile_options(test_list_node PRIVATE /W4 /WX)
else()
  target_compile_options(test_list_node PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_link_libraries(test_list_node PRIVATE linked_list)

add_test(NAME test_list_node COMMAND test_list_node)

message(STATUS "-- test_list_node")
