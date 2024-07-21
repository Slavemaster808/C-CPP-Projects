#include <libindexer/indexer.hpp>

#include <iostream>

#include <picosha2.h>

namespace indexer {
Index indexBuilder::getIndex() const {
  return index;
}
void indexBuilder::addDocument(size_t id, const std::string& str) {
  index.docs.insert({id, str});

  std::unordered_map<std::string, int> mp;
  mp = fts::splitByNgrams(
      str,
      config.stopWords,
      mp,
      config.ngram_min_length,
      config.ngram_max_length);
  for (const auto& i : mp) {
    index.entries[i.first][id].insert(i.second);
  }
}

void textIndexWriter::write(const std::string& path, const Index& index) {
  size_t totalDocs = 0;
  for (const auto& i : index.docs) {
    std::ofstream file(path + "index/docs/" + std::to_string(i.first));
    file << i.second;
    totalDocs++;
  }

  std::ofstream totalDocsFile(path + "index/total_docs");
  totalDocsFile << totalDocs;

  for (const auto& i : index.entries) {
    std::vector<unsigned char> hash(32);
    picosha2::hash256(i.first.begin(), i.first.end(), hash.begin(), hash.end());

    const std::string checkHash = path + "index/entries/" +
        picosha2::bytes_to_hex_string(hash.begin(), hash.end()).substr(0, 6);

    std::ofstream file(checkHash, std::ios::app);
    for (const auto& j : i.second) {
      for (const auto& k : j.second) {
        file << i.first << " " << j.first << " " << k << " ";
      }
      // file << std::endl;
    }
  }
}
}  // namespace indexer