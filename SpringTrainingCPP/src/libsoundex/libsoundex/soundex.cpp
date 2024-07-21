#include <libsoundex/soundex.hpp>

#include <rapidcsv.h>

#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

namespace cscsoundex {
uint32_t soundexHash(std::string_view str) {
  const std::unordered_map<char, char> consonantsToDigits{
      {'b', '1'},
      {'f', '1'},
      {'p', '1'},
      {'v', '1'},
      {'c', '2'},
      {'g', '2'},
      {'j', '2'},
      {'k', '2'},
      {'q', '2'},
      {'s', '2'},
      {'x', '2'},
      {'z', '2'},
      {'d', '3'},
      {'t', '3'},
      {'l', '4'},
      {'m', '5'},
      {'n', '5'},
      {'r', '6'}};

  const std::set<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};

  std::string resultHashStr(str);
  const char first = resultHashStr[0];

  auto it = std::remove_if(
      resultHashStr.begin() + 1, resultHashStr.end(), [](auto ch) {
        return ch == 'h' || ch == 'w';
      });

  resultHashStr.erase(it, resultHashStr.end());

  std::transform(
      resultHashStr.begin(),
      resultHashStr.end(),
      resultHashStr.begin(),
      [&consonantsToDigits](auto ch) {
        ch = std::tolower(ch);

        return consonantsToDigits.contains(ch) ? consonantsToDigits.at(ch) : ch;
      });

  it = std::unique(
      resultHashStr.begin(), resultHashStr.end(), [](auto ch1, auto ch2) {
        return std::isdigit(ch1) && std::isdigit(ch2) && ch1 == ch2;
      });

  resultHashStr.erase(it, resultHashStr.end());

  it = std::remove_if(
      resultHashStr.begin() + 1, resultHashStr.end(), [&vowels](auto ch) {
        return vowels.contains(ch);
      });

  resultHashStr.erase(it, resultHashStr.end());

  resultHashStr[0] = static_cast<char>(std::toupper(first));

  if (resultHashStr.size() < 4) {
    resultHashStr.append(4 - resultHashStr.size(), '0');
  }

  // std::cout << resultHashStr << "\n";

  const uint32_t result = strToHash(resultHashStr);

  return result;
}

uint32_t strToHash(const std::string& str) {
  uint32_t hash = 0;
  for (size_t i = 0; i < 4; ++i) {
    hash |= static_cast<unsigned char>(str[i]);
    if (i < 3) {
      hash <<= static_cast<unsigned int>(8);
    }
  }
  return hash;
}

std::string hashToStr(uint32_t hash) {
  std::string str;
  for (int i = 3; i != -1; --i) {
    const unsigned char ch = hash >> static_cast<unsigned int>(i * 8);
    str += static_cast<char>(ch);
  }
  return str;
}

namesMap parserCSV(const std::string& str) {
  std::vector<std::string> names;

  const rapidcsv::Document doc("./" + str);
  names = doc.GetColumn<std::string>("name");

  namesMap resultNamesMap;
  for (const auto& name : names) {
    const uint32_t hash = soundexHash(name);
    resultNamesMap.insert({hash, name});
  }

  // std::cout << resultNamesMap.size() << "\n";

  return resultNamesMap;
}
}  // namespace cscsoundex