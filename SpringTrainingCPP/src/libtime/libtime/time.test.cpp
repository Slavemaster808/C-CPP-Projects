#include <libtime/time.hpp>

#include <gtest/gtest.h>

// using namespace csctime::literals;
TEST(TimeTest, Equality) {
  const csctime::TimeSpan ts1(100);
  const csctime::TimeSpan ts2(100);

  const bool res = ts1 == ts2;
  ASSERT_EQ(res, true);
}

TEST(TimeTest, NotEquality) {
  const csctime::TimeSpan ts1(100);
  const csctime::TimeSpan ts2(200);

  const bool res = ts1 != ts2;
  ASSERT_EQ(res, true);
}

TEST(TimeTest, GreaterEQ) {
  const csctime::TimeSpan ts1(100);
  const csctime::TimeSpan ts2(100);

  const bool res = ts1 >= ts2;
  ASSERT_EQ(res, true);
}

TEST(TimeTest, Add) {
  const csctime::TimeSpan ts1(100);
  const csctime::TimeSpan ts2(100);

  const csctime::TimeSpan res = ts1 + ts2;
  ASSERT_EQ(res.getSeconds(), 200);
}

TEST(TimeTest, Sub) {
  const csctime::TimeSpan ts1(100);
  const csctime::TimeSpan ts2(100);

  const csctime::TimeSpan res = ts1 - ts2;
  ASSERT_EQ(res.getSeconds(), 0);
}

TEST(TimeTest, OutputStreamOperator) {
  const csctime::TimeSpan timeSpan(3661);  // 1 hour, 1 minute, 1 second
  std::ostringstream oss;
  oss << timeSpan;
  EXPECT_EQ(oss.str(), "00d01h01m01s");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
