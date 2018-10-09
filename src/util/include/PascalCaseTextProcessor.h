#pragma once

#include <string>

namespace util {
  class PascalCaseTextProcessor {
  public:
    virtual ~PascalCaseTextProcessor() = 0;

    virtual void process(std::string &str) const = 0;
  };

  inline util::PascalCaseTextProcessor::~PascalCaseTextProcessor() = default;
}




