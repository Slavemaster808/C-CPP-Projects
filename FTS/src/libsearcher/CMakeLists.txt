set(target_name searcher)

add_library(${target_name} STATIC
  libsearcher/searcher.cpp
  libsearcher/searcher.hpp)

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
    fts
    indexer
    picosha2
)

# testing

set(target_name_test searcher_tests)

add_executable(${target_name_test})

target_sources(
  ${target_name_test}
  PRIVATE
    libsearcher/searcher.test.cpp
)

set_compile_options(${target_name_test})

target_link_libraries(
  ${target_name_test}
  PUBLIC
    gtest_main
    indexer
    fts
    searcher
)

target_include_directories(
  ${target_name_test}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

include(GoogleTest)
gtest_discover_tests(${target_name_test})
