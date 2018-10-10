#pragma once

#include "PascalCaseTextProcessor.h"

namespace util {
  class PascalCaseTextProcessorImp : public PascalCaseTextProcessor {
  public:
    void process(std::string &text) const final;
  };
}