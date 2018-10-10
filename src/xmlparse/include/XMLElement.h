#pragma once

#include <string>
#include <memory>
#include <vector>
#include "XMLAttribute.h"

namespace xmlparse {
  class XMLElement {
  public:
    typedef std::shared_ptr<XMLElement> SharedXMLElement;

    virtual ~XMLElement() = default;

    virtual bool hasValue() const = 0;

    virtual std::optional<std::string> name() const = 0;

    virtual SharedXMLElement firstChildElement() const = 0;

    virtual SharedXMLElement firstChildElement(const std::string &name) const = 0;

    virtual std::shared_ptr<XMLAttribute> findAttribute(const std::string &name) const = 0;

    virtual SharedXMLElement nextSiblingElement() const = 0;

    virtual SharedXMLElement nextSiblingElement(const std::string &name) const = 0;

    virtual std::vector<SharedXMLElement> children() const = 0;

    virtual std::vector<SharedXMLElement> children(const std::string &name) const = 0;
  };
}

