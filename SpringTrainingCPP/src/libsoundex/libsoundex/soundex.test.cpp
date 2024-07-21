#include <libsoundex/soundex.hpp>

#include <gtest/gtest.h>

TEST(SoundexTest, soundexTest1) {
  const std::string_view str = "Ayah";
  const uint32_t hash = cscsoundex::soundexHash(str);
  const std::string strHash = cscsoundex::hashToStr(hash);
  const uint32_t convertedHash = cscsoundex::strToHash(strHash);
  ASSERT_EQ(hash, convertedHash);
}

TEST(SoundexTest, soundexTest2) {
  const std::string_view str = "Aya";
  const uint32_t hash = cscsoundex::soundexHash(str);
  const std::string strHash = cscsoundex::hashToStr(hash);
  const uint32_t convertedHash = cscsoundex::strToHash(strHash);
  ASSERT_EQ(hash, convertedHash);
}

TEST(SoundexTest, soundexTest3) {
  const std::string_view str = "Ava";
  const uint32_t hash = cscsoundex::soundexHash(str);
  const std::string strHash = cscsoundex::hashToStr(hash);
  const uint32_t convertedHash = cscsoundex::strToHash(strHash);
  ASSERT_EQ(hash, convertedHash);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}