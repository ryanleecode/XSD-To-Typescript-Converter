#pragma once

#include <string>

namespace tsgen {
  class TypescriptModule {
  public:
    virtual ~TypescriptModule() = default;

    virtual std::string generateTypescriptSchema() = 0;

    virtual std::string getModuleName() const = 0;
  };
}