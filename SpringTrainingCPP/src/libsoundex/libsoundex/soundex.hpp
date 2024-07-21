#pragma once

#include <map>
#include <string>
#include <string_view>

using namesMap = std::multimap<uint32_t, std::string>;

namespace cscsoundex {
uint32_t soundexHash(std::string_view str);

uint32_t strToHash(const std::string& str);

std::string hashToStr(uint32_t hash);

namesMap parserCSV(const std::string& str);
}  // namespace cscsoundex
