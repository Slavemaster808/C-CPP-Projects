// CPP Examples

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#ifndef mode
#define mode
#endif

namespace examples {
void newDelete(void) {  // 12.2
#ifndef mode
  typedef int arrT[88];
  int* p = new arrT();
  delete[] p;
#endif

#ifndef mode
  std::string* ps = new std::string[2];
  *ps = "hello";
  *(ps + 1) = "world";
  std::cout << *ps << " " << *(ps + 1) << " " << ps[0][0] << '\n';
  delete[] ps;
#endif

  std::string* ps2 = new std::string();
  *ps2 = "test";
  delete ps2;

  std::unique_ptr<int[]> up(new int[88]());
  up[0] = 1;
  up.release();

#ifndef mode
  std::unique_ptr<std::string> upstr(new std::string("test"));
  const char ch = upstr.get()->at(0);
  std::string* ch = upstr.get();
  std::cout << ch << '\n';
  std::cout << *upstr.get() << '\n';
  upstr.release();

  std::unique_ptr<int[]> u(p);
  u.release();
#endif

#ifndef mode
  const char* str1 = "Hello ";  // Ex 12.23
  const char* str2 = "World";
  char* strres = new char[strlen(str1) + strlen(str2) + 1];
  std::strcpy(strres, str1);
  std::strcat(strres, str2);
  std::cout << strres << '\n';
  delete[] strres;
#endif

#ifndef mode
  char* pstr = new char[10];  // Ex 12.24
  std::cin.getline(pstr, 10);
  std::cout << "Input: " << pstr << '\n';
  delete[] pstr;
#endif
}

void allocatorTopic(void) {  // 12.2.2
#ifndef mode
  std::allocator<std::string> alloc;
  std::string* pstr = alloc.allocate(3);
  *pstr = "test";
  *(pstr + 1) = "test2";
  std::cout << *pstr << *(pstr + 1) << '\n';
  alloc.deallocate(pstr, 3);
#endif

#ifndef mode
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::allocator<std::vector<int>> alloc;
  auto pvec = alloc.allocate(vec.size() * 2);

  auto q = std::uninitialized_copy(vec.begin(), vec.end(), pvec);
  std::uninitialized_fill(q, q + vec.size(), 0);
  alloc.deallocate(pvec, vec.size() * 2);
#endif

#ifdef mode  // Ex 12.26
  std::allocator<std::string> alloc;
  std::string* pstr = alloc.allocate(3);
  std::string str;
  auto q = pstr;

  while (std::getline(std::cin, str) && q < pstr + 3) {
    *q++ = str;
  }

  for (auto p = pstr; p != q; ++p) {
    std::cout << *p << '\n';
  }
  alloc.deallocate(pstr, 3);
#endif
}

// 12.3
using lineNo = std::vector<std::string>::size_type;
class QueryResult {
 private:
  std::string instr;
  std::shared_ptr<std::set<lineNo>> lines;
  std::shared_ptr<std::vector<std::string>> file;

 public:
  QueryResult(
      std::string s,
      std::shared_ptr<std::set<lineNo>> p,
      std::shared_ptr<std::vector<std::string>> f)
      : instr(s), lines(p), file(f){};

  friend std::ostream& operator<<(std::ostream& os, const QueryResult& qr) {
    os << qr.instr << " occurs " << qr.lines->size() << " times\n";
    for (auto num : *qr.lines) {
      os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << '\n';
    }
    return os;
  }
};

class TextQuery {
 private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string, std::shared_ptr<std::set<lineNo>>> wm;

 public:
  TextQuery(std::ifstream& is) : file(new std::vector<std::string>) {
    std::string text;
    while (std::getline(is, text)) {
      file->push_back(text);
      int n = file->size() - 1;
      std::istringstream line(text);
      std::string word;
      while (line >> word) {
        auto& lines = wm[word];
        // std::cout << *lines->begin();
        if (!lines) {
          //   std::cout << "TEST" << '\n' << '\n';
          lines.reset(new std::set<lineNo>);
          lines->insert(n);
        }
      }
    }
  }

  QueryResult query(const std::string& instr) const {
    std::shared_ptr<std::set<lineNo>> nodata(new std::set<lineNo>);
    auto loc = wm.find(instr);
    if (loc == wm.end()) {
      return QueryResult(instr, nodata, file);
    } else {
      return QueryResult(instr, loc->second, file);
    }
  }
};

void runQueries(std::ifstream& infile) {
  TextQuery tq(infile);
  while (true) {
    std::cout << "Enter word to look for/q to quit: ";
    std::string str;
    if (!(std::getline(std::cin, str)) || str == "q") {
      break;
    }
    std::cout << tq.query(str) << '\n';
  }
}

// void testFoo(std::string& str) {
//   std::transform(str.begin(), str.end(), str.begin(), [](char c) {
//     return std::toupper(c);
//   });
// }

void testSome() {
  std::set<int> s = {1, 2, 3, 4, 5};
  std::shared_ptr<std::set<int>> s2(new std::set<int>(s));
  std::cout << *s2->begin() << '\n';
}
}  // namespace examples

int main() {
  //   examples::newDelete();
  //   examples::allocatorTopic();

  std::ifstream file("./test.txt");
  examples::runQueries(file);
}