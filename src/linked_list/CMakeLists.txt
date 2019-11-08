set(SOURCES
)

set(HEADERS
    list_node.h
)

add_library(linked_list INTERFACE)

target_include_directories(linked_list INTERFACE "${C_FUN_SOURCE_DIR}/src")

target_compile_features(linked_list INTERFACE c_std_99)

if(MSVC)
  target_compile_options(linked_list INTERFACE /W4 /WX)
else()
  target_compile_options(linked_list INTERFACE -Wall -Wextra -pedantic -Werror)
endif()

# source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
