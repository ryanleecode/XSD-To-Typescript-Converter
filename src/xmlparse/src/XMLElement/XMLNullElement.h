#pragma once

#include <XMLElement.h>

namespace xmlparse {
  class XMLNullElement : public XMLElement {
  public:
    XMLNullElement() = default;

    bool hasValue() const override;

    std::optional<std::string> name() const override;

    SharedXMLElement firstChildElement(const std::string &name) const override;

    SharedXMLElement firstChildElement() const override;

    std::shared_ptr<XMLAttribute> findAttribute(const std::string &name) const override;

    SharedXMLElement nextSiblingElement(const std::string &name) const override;

    SharedXMLElement nextSiblingElement() const override;

    std::vector<SharedXMLElement> children() const override;

    std::vector<SharedXMLElement> children(const std::string &name) const override;
  };
}




