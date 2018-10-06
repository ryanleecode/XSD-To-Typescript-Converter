#pragma once

#include <string>
#include <vector>
#include <memory>
#include <set>
#include "TypescriptPrimitive.h"
#include "SimpleType.h"

namespace tsgen {
  class SimpleTypeImp : public SimpleType {
  public:
    explicit SimpleTypeImp(const xmlparse::XMLElement &simpleTypeElement);

    std::string toTypescriptDefinition() const override;

  protected:
    std::string name_;
    std::string type_;
    const std::set<std::string> possibleValues_;
  };
}




