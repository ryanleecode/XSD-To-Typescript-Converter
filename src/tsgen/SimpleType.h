#pragma once

#include <string>
#include <vector>
#include <memory>
#include <set>
#include "TypescriptPrimitive.h"
#include "../util/NotImplementedException.h"
#include "../xmlparse/XMLElement/XMLElement.h"

namespace tsgen {
  class ISimpleType {
  public:
    virtual ~ISimpleType() = default;

    virtual std::string toTypescriptDefinition() const {
      throw util::NotImplementedException();
    };
  };

  class SimpleType : public ISimpleType {
  public:
    explicit SimpleType(const xmlparse::XMLElement &simpleTypeElement);

    std::string toTypescriptDefinition() const override;

  protected:
    std::string name_;
    std::string type_;
    const std::set<std::string> possibleValues_;
  };
}




