#pragma once

#include <string>

namespace tsgen {
  class SimpleType {
  public:
    virtual ~SimpleType() = default;

    virtual std::string toTypescriptDefinition() const;
  };
}
