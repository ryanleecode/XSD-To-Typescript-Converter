#pragma once

#include <string>
#include <vector>
#include <memory>
#include "xsd_primitive.h"

namespace tsgen {

  template<typename T>
  class SimpleType {
  public:
    SimpleType(const std::string &name,
               XSDPrimitive type,
               std::unique_ptr<std::vector<T>> possibleValues);

    virtual std::string toTypescriptDefinition() const;

  protected:
    std::string name_;
    XSDPrimitive type_;
    std::unique_ptr<std::vector<T>> possibleValues_;
  };

  template
  class SimpleType<std::string>;
}




