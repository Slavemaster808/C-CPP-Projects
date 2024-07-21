set(target_name csctime)

# add_executable(${target_name})

add_library(${target_name} STATIC
  libtime/time.hpp
  libtime/time.cpp)

include(CompileOptions)
set_compile_options(${target_name})

target_include_directories(
  ${target_name}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

# testing

set(target_name_test all_test)

add_executable(${target_name_test})

target_sources(
  ${target_name_test}
  PRIVATE
    libtime/time.test.cpp
)

set_compile_options(${target_name_test})

target_link_libraries(
  ${target_name_test}
  PUBLIC
    gtest_main
    csctime
)

target_include_directories(
  ${target_name_test}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

include(GoogleTest)
gtest_discover_tests(${target_name_test})
