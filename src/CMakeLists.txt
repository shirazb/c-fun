set(SOURCES
    list_node.c
)

set(HEADERS
    list_node.h
)

add_library(list_node STATIC ${SOURCES} ${HEADERS})

target_include_directories(list_node PUBLIC "${C_FUN_SOURCE_DIR}/src")

target_compile_features(list_node PUBLIC c_std_99)

if(MSVC)
  target_compile_options(list_node PRIVATE /W4 /WX)
else()
  target_compile_options(list_node PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
