set(target_name appSoundex)

add_executable(${target_name})

include(CompileOptions)
set_compile_options(${target_name})

target_sources(
  ${target_name}
  PRIVATE
    appSoundex/main.cpp
)

target_link_libraries(
  ${target_name}
  PRIVATE
    cscsoundex
    rapidcsv
    nlohmann_json::nlohmann_json
    cxxopts
)
