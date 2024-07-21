#include <algorithm>
#include <cctype>
#include <iostream>
#include <libfts/funcs.hpp>

namespace fts {
void deletePunct(std::string& ptr) {
  auto it = std::remove_if(ptr.begin(), ptr.end(), [](unsigned char ch) {
    return std::ispunct(ch);
  });

  ptr.erase(it, ptr.end());
}

void strToLower(std::string& ptr) {
  std::transform(ptr.begin(), ptr.end(), ptr.begin(), [](unsigned char ch) {
    return std::tolower(ch);
  });
}

void storeAllWords(std::string& ptr, std::vector<std::string>& v) {
  size_t initPosition = ptr.find_first_not_of(' ', 0);
  size_t position = ptr.find(' ', initPosition);

  while (position != std::string::npos) {
    v.push_back(ptr.substr(initPosition, position - initPosition));
    initPosition = ptr.find_first_not_of(' ', position);
    position = ptr.find(' ', initPosition);
  }
  if (initPosition != std::string::npos) {
    v.push_back(ptr.substr(initPosition, ptr.size()));
  }
}

void deleteStopWords(
    std::vector<std::string>& v,
    const std::vector<std::string>& stopWords) {
  auto it = std::remove_if(v.begin(), v.end(), [&stopWords](std::string& x) {
    return (
        std::find(stopWords.begin(), stopWords.end(), x) != stopWords.end());
  });

  v.erase(it, v.end());
}

void splitNGrams(
    std::vector<std::string>& v,
    std::unordered_map<std::string, int>& nGramsMap,
    size_t ngram_min_length,
    size_t ngram_max_length) {
  int ngramIndex = 0;

  std::for_each(
      v.begin(),
      v.end(),
      [&nGramsMap, &ngram_min_length, &ngram_max_length, &ngramIndex](
          std::string& item) {
        const size_t size = item.size();
        if (size < ngram_max_length && size > ngram_min_length) {
          for (size_t i = ngram_min_length; i <= size; i++) {
            nGramsMap.insert({item.substr(0, i), ngramIndex});
          }
          ngramIndex++;
        } else if (size >= ngram_max_length) {
          for (size_t i = ngram_min_length; i <= ngram_max_length; i++) {
            nGramsMap.insert({item.substr(0, i), ngramIndex});
          }
          ngramIndex++;
        }
      });
}

std::unordered_map<std::string, int> splitByNgrams(
    std::string ptr,
    const std::vector<std::string>& stopWords,
    std::unordered_map<std::string, int> mp,
    size_t nGrams_min,
    size_t nGrams_max) {
  std::vector<std::string> vec;

  fts::deletePunct(ptr);
  fts::strToLower(ptr);
  fts::storeAllWords(ptr, vec);
  fts::deleteStopWords(vec, stopWords);
  fts::splitNGrams(vec, mp, nGrams_min, nGrams_max);
  return mp;
}

void trimStart(std::string& str) {
  const size_t pos = str.find_first_not_of(' ');
  if (pos != std::string::npos) {
    str.erase(0, pos);
  }
}
}  // namespace fts