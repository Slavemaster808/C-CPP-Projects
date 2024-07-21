#pragma once
#include <libfts/funcs.hpp>
#include <set>

using Docs = std::unordered_map<size_t, std::string>;
using Entries = std::
    unordered_map<std::string, std::unordered_map<size_t, std::set<size_t>>>;

namespace indexer {
struct Index {
  Docs docs;
  Entries entries;
};

class indexWriter {
 public:
  virtual void write(const std::string& path, const Index& index) = 0;
  virtual ~indexWriter() = default;
};

class textIndexWriter : public indexWriter {
 public:
  void write(const std::string& path, const Index& index) override;
};

class indexBuilder {
 private:
  Index index;
  fts::Config config;

 public:
  explicit indexBuilder(fts::Config conf) : config(std::move(conf)){};
  indexBuilder() = default;
  Index getIndex() const;
  void addDocument(size_t id, const std::string& str);
};
}  // namespace indexer