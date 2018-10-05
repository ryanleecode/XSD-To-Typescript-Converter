#pragma once

#include <tinyxml2.h>
#include "XMLElement.h"

namespace xmlparse {
  class XMLElementAdapter : public XMLElement {
  public:
    XMLElementAdapter(const tinyxml2::XMLElement &xmlElement);

    bool hasValue() const override;

    std::optional<std::string> name() const override;

    std::unique_ptr<XMLElement> firstChildElement(const std::string &name) const override;

    std::unique_ptr<XMLElement> firstChildElement() const override;

    std::unique_ptr<XMLAttribute> findAttribute(const std::string &name) const override;

    std::unique_ptr<XMLElement> nextSiblingElement(const std::string &name) const override;

    std::unique_ptr<XMLElement> nextSiblingElement() const override;
  private:
    const tinyxml2::XMLElement &xmlElement_;
  };
}




