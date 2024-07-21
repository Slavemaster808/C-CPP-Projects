#include <libfts/funcs.hpp>
#include <libindexer/indexer.hpp>
#include <libsearcher/searcher.hpp>

#include <cxxopts.hpp>
#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>

using json = nlohmann::json;

int main(int argc, char** argv) {
  const std::filesystem::path p{"./config.json"};
  cxxopts::Options options("./app", "Text parser.");
  options.add_options()("c, config", "", cxxopts::value<std::string>())(
      "h, help", "Usage:\n--config [filename]\n--search\n")("s, search", "");

  auto result = options.parse(argc, argv);

  if (result.arguments().empty()) {
    std::cout << options.help() << '\n';
  }

  if (result.count("help") > 0U) {
    std::cout << options.help();
  }
  if (result.count("config") > 0) {
    std::ifstream file(result["config"].as<std::string>());
    if (!file) {
      std::cerr << "No such file." << '\n';
    } else {
      const json data = json::parse(file);
      fts::Config cnf;

      cnf.ngram_max_length = data["ngram_max_length"];
      cnf.ngram_min_length = data["ngram_min_length"];
      cnf.stopWords = data["stop_words"];

      file.close();

      int docId = 0;
      const std::string docPath = "./";
      indexer::indexBuilder idxBuilder(cnf);
      std::string text;
      while (true) {
        std::cout << "> ";
        std::cin >> docId;
        std::getline(std::cin, text);
        if (docId == -1) {
          break;
        }
        fts::trimStart(text);
        idxBuilder.addDocument(static_cast<size_t>(docId), text);
      }
      indexer::textIndexWriter writer;
      writer.write(docPath, idxBuilder.getIndex());
    }
  } else if (result.count("search") > 0) {
    std::string queryStr{"bye earth"};
    const searcher::textIndexAccessor accessor(std::string("./index"));
    const searcher::ResultVec res = searcher::search(queryStr, accessor);
    accessor.printResult(res);
  }
}