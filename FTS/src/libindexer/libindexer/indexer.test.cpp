#include <libindexer/indexer.hpp>

#include <gtest/gtest.h>

#include <filesystem>

TEST(IndexerTests, Index1) {
  indexer::indexBuilder builder;
  const std::string str = "test";
  builder.addDocument(0, str);
  indexer::Index index = builder.getIndex();
  const std::string checkStr = index.docs.at(0);
  ASSERT_EQ(checkStr, str);
}

TEST(IndexerTests, Index2) {
  indexer::indexBuilder builder;
  const std::string str = "test string";
  builder.addDocument(0, str);
  indexer::Index index = builder.getIndex();
  const std::string checkStr = index.docs.at(0);
  ASSERT_EQ(checkStr, str);
}

TEST(IndexerTests, Index3) {
  fts::Config cnf;
  cnf.stopWords = {"test"};
  cnf.ngram_min_length = 3;
  cnf.ngram_max_length = 6;

  indexer::indexBuilder builder(cnf);
  builder.addDocument(0, "test matrix");
  indexer::Index index = builder.getIndex();
  std::vector<std::string> vec;
  for (const auto& [str, _] : index.entries) {
    vec.push_back(str);
  }
  std::sort(vec.begin(), vec.end());
  const std::string str = index.entries.begin()->first;

  ASSERT_EQ(vec[0], "mat");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
