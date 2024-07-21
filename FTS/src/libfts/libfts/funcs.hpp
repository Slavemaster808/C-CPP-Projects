#pragma once
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace fts {
struct Config {
  std::vector<std::string> stopWords;
  size_t ngram_min_length = 0;
  size_t ngram_max_length = 0;
};

void deletePunct(std::string& ptr);

void strToLower(std::string& ptr);

void storeAllWords(std::string& ptr, std::vector<std::string>& v);

void deleteStopWords(
    std::vector<std::string>& v,
    const std::vector<std::string>& stopWords);

void splitNGrams(
    std::vector<std::string>& v,
    std::unordered_map<std::string, int>& nGramsMap,
    size_t ngram_min_length,
    size_t ngram_max_length);

std::unordered_map<std::string, int> splitByNgrams(
    std::string ptr,
    const std::vector<std::string>& stopWords,
    std::unordered_map<std::string, int> mp,
    size_t nGrams_min,
    size_t nGrams_max);

void trimStart(std::string& str);
}  // namespace fts