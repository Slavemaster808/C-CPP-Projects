#include <libfts/funcs.hpp>

#include <gtest/gtest.h>

TEST(FTSTests, Punct1) {
  std::string str = "Te.st, string..";
  fts::deletePunct(str);
  ASSERT_EQ(str, "Test string");
}

TEST(FTSTests, Register) {
  std::string str = "TEST STRING";
  fts::strToLower(str);
  ASSERT_EQ(str, "test string");
}

TEST(FTSTests, StoreInVec) {
  std::string str = "test";
  std::vector<std::string> vec;
  fts::storeAllWords(str, vec);
  ASSERT_EQ(vec[0], "test");
}

TEST(FTSTests, Normalized) {
  std::vector<std::string> vec = {"test"};
  const std::vector<std::string> nGrams = {"and", "dr", "an"};
  fts::deleteStopWords(vec, nGrams);
  ASSERT_EQ(vec[0], "test");
}

TEST(FTSTests, StoreInMap1) {
  std::vector<std::string> vec = {"test"};
  std::unordered_map<std::string, int> map;
  fts::splitNGrams(vec, map, 3, 6);
  ASSERT_EQ(map["tes"], 0);
}

TEST(FTSTests, StoreInMap2) {
  std::vector<std::string> vec = {"test"};
  std::unordered_map<std::string, int> map;
  fts::splitNGrams(vec, map, 3, 6);
  ASSERT_EQ(map["test"], 0);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
