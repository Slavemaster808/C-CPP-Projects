#include <libfts/funcs.hpp>
#include <libindexer/indexer.hpp>
#include <libsearcher/searcher.hpp>

#include <cxxopts.hpp>
#include <replxx.hxx>

#include <nlohmann/json.hpp>

#include <filesystem>
#include <iostream>

using json = nlohmann::json;

int main(int argc, char** argv) {
  cxxopts::Options options(
      "SearcherUtil", "Searcher for documents in the index file.");

  options.add_options()(
      "index", "Index file path.", cxxopts::value<std::string>())(
      "query", "Query string.", cxxopts::value<std::string>())(
      "h,help", "Usage");

  auto result = options.parse(argc, argv);

  if (result.count("help") != 0) {
    std::cout << options.help() << '\n';
  }

  if (result.count("index") == 0) {
    std::cout << options.help() << '\n';
  }

  const std::string indexPath = result["index"].as<std::string>();

  if (indexPath.empty()) {
    std::cout << "Invalid path." << '\n';
  }

  if (result.count("query") == 0) {
    const std::filesystem::path tempPath =
        std::filesystem::temp_directory_path();
    const std::filesystem::path histPath = tempPath / "replxx.hist";

    replxx::Replxx repl;
    repl.history_save(histPath);

    while (true) {
      std::string query = repl.input("> ");
      repl.clear_screen();

      if (query.empty()) {
        break;
      }

      const searcher::textIndexAccessor accessor(indexPath);
      const searcher::ResultVec result = searcher::search(query, accessor);
      accessor.printResult(result);
      repl.history_add(query);
    }
  } else {
    std::string query = result["query"].as<std::string>();

    if (query.empty()) {
      std::cout << "Invalid data." << '\n';
    } else {
      const searcher::textIndexAccessor accessor(indexPath);
      const searcher::ResultVec result = searcher::search(query, accessor);
      accessor.printResult(result);
    }
  }
}