#include <liblinkedlist/linkedlist.hpp>

#include <gtest/gtest.h>

#include <algorithm>
#include <list>

TEST(ListTest, IterTest) {
  csclinkedlist::LinkedList<int> eq_list{1, 2, 3, 4};
  const csclinkedlist::LinkedList<int>::iterator beg = eq_list.begin();
  const csclinkedlist::LinkedList<int>::iterator end = eq_list.end();

  const csclinkedlist::LinkedList<int> expected(beg, end);

  ASSERT_EQ(eq_list, expected);
}

TEST(ListTest, FrontBackTest) {
  const csclinkedlist::LinkedList<int> eq_list{1, 2, 3, 4};

  ASSERT_EQ(eq_list.front(), 1);
  ASSERT_EQ(eq_list.back(), 4);
}

TEST(ListTest, PushTest) {
  {
    csclinkedlist::LinkedList<int> eq_list{1, 2, 3};
    eq_list.push_back(5);
    const csclinkedlist::LinkedList<int> expected{1, 2, 3, 5};
    ASSERT_EQ(eq_list, expected);
  }
  {
    csclinkedlist::LinkedList<int> eq_list{1, 2, 3};
    eq_list.push_front(5);
    const csclinkedlist::LinkedList<int> expected{5, 1, 2, 3};
    ASSERT_EQ(eq_list, expected);
  }
}

TEST(ListTest, EmptyTest) {
  const csclinkedlist::LinkedList<int> eq_list{1, 2, 3};
  ASSERT_EQ(eq_list.empty(), false);
  const csclinkedlist::LinkedList<int> eq_list_1{};
  ASSERT_EQ(eq_list_1.empty(), true);
  ASSERT_EQ(eq_list.size(), 3);
  ASSERT_EQ(eq_list_1.size(), 0);
}

TEST(ListTest, CPConstructorTest) {
  const csclinkedlist::LinkedList<char> eq_list{'a', 'b', 'c', 'd'};
  const csclinkedlist::LinkedList<char> copy_list(eq_list);

  ASSERT_EQ(eq_list, copy_list);
}

TEST(ListTest, MVConstructorTest) {
  const csclinkedlist::LinkedList<int> eq_list{1, 2, 3};
  const csclinkedlist::LinkedList<int> move_list(std::move(eq_list));

  ASSERT_EQ((csclinkedlist::LinkedList<int>{1, 2, 3}), move_list);
}

TEST(ListTest, CPSignTest) {
  {
    const csclinkedlist::LinkedList<char> eq_list{'a', 'b', 'c', 'd'};
    csclinkedlist::LinkedList<char> copy_list{'a', 'b', 'c'};
    copy_list = eq_list;

    ASSERT_EQ(eq_list, copy_list);
  }
  {
    const csclinkedlist::LinkedList<char> eq_list{'a', 'b', 'c'};
    csclinkedlist::LinkedList<char> copy_list{'a', 'b', 'c'};
    copy_list = eq_list;

    ASSERT_EQ(eq_list, copy_list);
  }
}

TEST(ListTest, MVTest) {
  const csclinkedlist::LinkedList<int> eq_list{1, 2, 3};
  const csclinkedlist::LinkedList<int> move_list = std::move(eq_list);

  ASSERT_EQ((csclinkedlist::LinkedList<int>{1, 2, 3}), move_list);
}

TEST(ListTest, STLTest) {
  {
    const csclinkedlist::LinkedList<int> eq_list{1, 2, 3};
    const auto it = std::find(eq_list.begin(), eq_list.end(), 2);

    ASSERT_EQ(*it, 2);
  }

  {
    csclinkedlist::LinkedList<int> eq_list{1, 2, 3};
    std::reverse(eq_list.begin(), eq_list.end());

    ASSERT_EQ(eq_list, (csclinkedlist::LinkedList<int>{3, 2, 1}));
  }
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}