#pragma once

#include <string>
#include <vector>
#include <memory>
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

  template<typename T>
  class SimpleType : public ISimpleType {
  public:
    SimpleType(const xmlparse::XMLElement &simpleTypeElement);

    std::string toTypescriptDefinition() const override;

  protected:
    std::string name_;
    std::string type_;
    std::unique_ptr<std::vector<T>> possibleValues_;
  };

  template
  class SimpleType<std::string>;

  template
  class SimpleType<int>;
}




