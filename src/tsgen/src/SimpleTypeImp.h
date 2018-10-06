#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_set>
#include "TypescriptPrimitive.h"
#include "SimpleType.h"
#include <XMLElement.h>

namespace tsgen {
  class SimpleTypeImp : public SimpleType {
  public:
    explicit SimpleTypeImp(const xmlparse::XMLElement &simpleTypeElement);

    std::string toTypescriptDefinition() const override;

  protected:
    std::string name_;
    std::string type_;
  };
}




