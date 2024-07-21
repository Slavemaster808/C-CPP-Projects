set(target_name csclist)

# add_executable(${target_name})

add_library(${target_name} STATIC
  liblinkedlist/linkedlist.hpp
  liblinkedlist/linkedlist.cpp
)

include(CompileOptions)
set_compile_options(${target_name})

target_include_directories(
  ${target_name}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

# testing

set(target_name_test list_test)

add_executable(${target_name_test})

target_sources(
  ${target_name_test}
  PRIVATE
    liblinkedlist/linkedlist.test.cpp
)

set_compile_options(${target_name_test})

target_link_libraries(
  ${target_name_test}
  PUBLIC
    gtest_main
    csclist
)

target_include_directories(
  ${target_name_test}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

include(GoogleTest)
gtest_discover_tests(${target_name_test})
