set(target_name indexerutil)

add_executable(${target_name})

include(CompileOptions)
set_compile_options(${target_name})

target_sources(
  ${target_name}
  PRIVATE
    libutils/indexerutil.cpp
)

target_link_libraries(
  ${target_name}
  PRIVATE
    fts  
    indexer
    searcher
    cxxopts
    nlohmann_json::nlohmann_json
    rapidcsv
)

set(target_name searcherutil)

add_executable(${target_name})

include(CompileOptions)
set_compile_options(${target_name})

target_sources(
  ${target_name}
  PRIVATE
    libutils/searcherutil.cpp
)

target_link_libraries(
  ${target_name}
  PRIVATE
    fts  
    indexer
    searcher
    cxxopts
    nlohmann_json::nlohmann_json
    replxx
)