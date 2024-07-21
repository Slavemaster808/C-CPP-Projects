#include <libsoundex/soundex.hpp>

#include <cxxopts.hpp>
#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>

using json = nlohmann::json;

int main(int argc, char** argv) {
  cxxopts::Options options("./appSoundex", "Soundex Hash.");
  options.add_options()("p, path", "", cxxopts::value<std::string>())(
      "h, help", "Usage:\n--path [filename]");

  auto result = options.parse(argc, argv);

  if (result.arguments().empty()) {
    std::cout << options.help() << '\n';
  }

  if (result.count("help") > 0U) {
    std::cout << options.help();
  }

  if (result.count("path") > 0) {
    const std::string filename = result["path"].as<std::string>();
    const std::ifstream file(filename);

    if (!file) {
      std::cout << "File not found: " << result["path"].as<std::string>()
                << "\n";
    } else {
      const namesMap resultNamesMap = cscsoundex::parserCSV(filename);

      // std::cout << resultNamesMap.size() << "\n";

      std::ofstream outFile("key.json");
      json jsonList({});

      for (const auto& it : resultNamesMap) {
        jsonList[cscsoundex::hashToStr(it.first)].push_back(it.second);
      }
      outFile << jsonList.dump(2);
      outFile << jsonList;
    }
  }
}