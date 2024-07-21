#include <libfts/funcs.hpp>
#include <libindexer/indexer.hpp>

#include <cxxopts.hpp>
#include <nlohmann/json.hpp>

#include <rapidcsv.h>

#include <iostream>

using json = nlohmann::json;

int main(int argc, char** argv) {
  cxxopts::Options options("IndexerUtil", "Program to index documents.");

  options.add_options()("csv", "CSV file path.", cxxopts::value<std::string>())(
      "index", "Index file path.", cxxopts::value<std::string>())(
      "h,help", "Usage");

  auto result = options.parse(argc, argv);

  if (result.arguments().empty()) {
    std::cout << options.help() << '\n';
  }

  if (result.count("help") > 0U) {
    std::cout << options.help();
  }

  if (result.count("csv") == 0 || result.count("index") == 0) {
    std::cout << options.help() << '\n';
  }

  if (result.count("csv") > 0 && result.count("index") > 0) {
    const std::string csvPath = result["csv"].as<std::string>();
    const std::string indexPath = result["index"].as<std::string>();

    if (csvPath.empty() || indexPath.empty()) {
      std::cout << "Invalid data." << '\n';
    }

    std::vector<size_t> docIds;
    std::vector<std::string> titles;

    const rapidcsv::Document doc(csvPath);
    docIds = doc.GetColumn<size_t>("bookID");
    titles = doc.GetColumn<std::string>("title");

    if (docIds.empty() || titles.empty()) {
      std::cout << "Invalid document data." << '\n';
    }

    if (docIds.size() != titles.size()) {
      std::cout << "Sizes of document ids and titles do not match."
                << std::endl;
    }

    std::ifstream file("./config.json");
    const json data = json::parse(file);
    fts::Config cnf;

    cnf.ngram_max_length = data["ngram_max_length"];
    cnf.ngram_min_length = data["ngram_min_length"];
    cnf.stopWords = data["stop_words"];

    indexer::indexBuilder idxBuilder(cnf);

    for (size_t i = 0; i < docIds.size(); i++) {
      idxBuilder.addDocument(static_cast<size_t>(docIds[i]), titles[i]);
    }

    indexer::textIndexWriter writer;
    writer.write(indexPath, idxBuilder.getIndex());
  }
}