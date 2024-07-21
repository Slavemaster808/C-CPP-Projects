set(target_name cscsoundex)

# add_executable(${target_name})

add_library(${target_name} STATIC
  libsoundex/soundex.hpp
  libsoundex/soundex.cpp)

include(CompileOptions)
set_compile_options(${target_name})

target_include_directories(
  ${target_name}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(
  ${target_name}
  PRIVATE
    rapidcsv
)

# testing

set(target_name_test soundex_tests)

add_executable(${target_name_test})

target_sources(
  ${target_name_test}
  PRIVATE
    libsoundex/soundex.test.cpp
)

set_compile_options(${target_name_test})

target_link_libraries(
  ${target_name_test}
  PUBLIC
    gtest_main
    cscsoundex
)

target_include_directories(
  ${target_name_test}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

include(GoogleTest)
gtest_discover_tests(${target_name_test})
