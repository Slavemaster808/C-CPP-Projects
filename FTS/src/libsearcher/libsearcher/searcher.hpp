#pragma once
#include <libindexer/indexer.hpp>

namespace searcher {
using Score = std::map<size_t, double>;

using ResultVec = std::vector<std::pair<size_t, double>>;

struct TermInfos {
  std::map<size_t, double> termFrequencies;
  double documentFrequency = 0;
};

class indexAccessor {
 public:
  virtual TermInfos getTermInfos(const std::string& ptr) const = 0;
  virtual std::string loadDocument(const size_t id) const = 0;
  virtual size_t totalDocs() const = 0;
  virtual void printResult(const ResultVec& resultVec) const = 0;
  virtual ~indexAccessor() = default;
};

class textIndexAccessor : public indexAccessor {
 private:
  std::string path;

 public:
  TermInfos getTermInfos(const std::string& ptr) const override;
  std::string loadDocument(const size_t id) const override;
  size_t totalDocs() const override;
  void printResult(const ResultVec& resultVec) const override;
  textIndexAccessor(std::string path) : path(std::move(path)) {
  }
  std::string getPath() const {
    return path;
  }
};

ResultVec search(std::string& query, const textIndexAccessor& index);
void scoreCounter(
    const TermInfos& termInfs,
    const size_t totalDocs,
    Score& score);

void printResult(const ResultVec& resultVec);
}  // namespace searcher