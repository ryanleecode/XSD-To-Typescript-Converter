#pragma once

#include <string>
#include <memory>
#include "XMLAttribute.h"

namespace xmlparse {
  class XMLElement {
  public:
    virtual ~XMLElement() = default;

    virtual std::string name() const = 0;

    virtual const std::shared_ptr<XMLElement> firstChildElement(const std::string &name  = nullptr) const = 0;

    virtual std::shared_ptr<XMLElement> firstChildElement(const std::string &name = nullptr) = 0;

    virtual const std::shared_ptr<XMLAttribute> findAttribute(const std::string &name) const = 0;

    virtual const std::shared_ptr<XMLAttribute>	nextSiblingElement(std::string name = nullptr) const = 0;
  };
}

