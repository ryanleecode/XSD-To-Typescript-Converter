#pragma once

#include <XMLElement.h>

namespace xmlparse {
  class XMLNullElement : public XMLElement {
  public:
    XMLNullElement() = default;

    bool hasValue() const override;

    std::optional<std::string> name() const override;

    std::unique_ptr<XMLElement> firstChildElement(const std::string &name) const override;

    std::unique_ptr<XMLElement> firstChildElement() const override;

    std::unique_ptr<XMLAttribute> findAttribute(const std::string &name) const override;

    std::unique_ptr<XMLElement> nextSiblingElement(const std::string &name) const override;

    std::unique_ptr<XMLElement> nextSiblingElement() const override;
  };
}




