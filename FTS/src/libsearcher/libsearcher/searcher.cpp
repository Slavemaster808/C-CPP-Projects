#include <libsearcher/searcher.hpp>

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>

#include <picosha2.h>

namespace searcher {
size_t textIndexAccessor::totalDocs() const {
  std::ifstream file{path + "/total_docs", std::ios_base::in};
  size_t totalDocsCount = 0;
  file >> totalDocsCount;
  return totalDocsCount;
}

std::string textIndexAccessor::loadDocument(const size_t id) const {
  std::ifstream file(path + "docs/" + std::to_string(id));
  std::string str;

  if (!file.is_open()) {
    throw std::invalid_argument(
        "Invalid open file for documents: " + std::to_string(id));
  }
  std::getline(file, str);
  return str;
}

TermInfos textIndexAccessor::getTermInfos(const std::string& ptr) const {
  std::vector<unsigned char> hash(32);

  picosha2::hash256(ptr.begin(), ptr.end(), hash.begin(), hash.end());
  const std::string checkHash = path + "/entries/" +
      picosha2::bytes_to_hex_string(hash.begin(), hash.end()).substr(0, 6);

  std::ifstream file(checkHash);

  TermInfos termInfs;
  std::vector<std::string> vecForTerms;
  if (file.is_open()) {
    std::string line;
    std::getline(file, line);
    fts::storeAllWords(line, vecForTerms);
    double countFreq = 0.0;
    for (size_t i = 0; i < vecForTerms.size(); i += 3) {
      countFreq += 1.0;
    }
    termInfs.documentFrequency = countFreq;

    double countPos = 0.0;
    for (size_t i = 1; i < vecForTerms.size(); i += 3) {
      countPos += 1.0;
      termInfs.termFrequencies[std::stoi(vecForTerms[i])] += countPos;
    }
  }
  // for (const auto& i : termInfs.termFrequencies) {
  //   std::cout << i.first << " " << i.second << '\n';
  // }
  return termInfs;
}

void scoreCounter(
    const TermInfos& termInfs,
    const size_t totalDocs,
    Score& score) {
  for (const auto& i : termInfs.termFrequencies) {
    const double iDFT =
        std::log(static_cast<double>(totalDocs) / termInfs.documentFrequency);
    const double finalRes = i.second * iDFT;
    // std::cout << iDFT << ' ' << i.second << '\n';
    score[i.first] += finalRes;
  }
}

ResultVec search(std::string& query, const textIndexAccessor& index) {
  Score resultScore;
  std::vector<std::string> vecForQuery;
  std::vector<std::vector<std::string>> test;
  fts::storeAllWords(query, vecForQuery);
  test.push_back(vecForQuery);

  for (const auto& i : test) {
    for (const auto& j : i) {
      const TermInfos termInfs = index.getTermInfos(j);
      scoreCounter(termInfs, index.totalDocs(), resultScore);
    }
  }
  ResultVec resultVec(resultScore.begin(), resultScore.end());

  std::sort(
      resultVec.begin(),
      resultVec.end(),
      [](const auto& score1, const auto& score2) {
        if (score1.second == score2.second) {
          return score1.first < score2.first;
        }
        return score1.second > score2.second;
      });
  return resultVec;
}

void textIndexAccessor::printResult(const ResultVec& resultVec) const {
  for (const auto& i : resultVec) {
    std::ifstream file(path + "/docs/" + std::to_string(i.first));
    std::string line;
    std::getline(file, line);
    std::cout << i.first << " " << i.second << " " << line << '\n';
  }
}
}  // namespace searcher