#pragma once

#include <tinyxml2.h>
#include <vector>
#include "XMLElement.h"

namespace xmlparse {
  class XMLElementAdapter : public XMLElement {
  public:
    explicit XMLElementAdapter(const tinyxml2::XMLElement &xmlElement);

    bool hasValue() const override;

    std::optional<std::string> name() const override;

    SharedXMLElement firstChildElement(const std::string &name) const override;

    SharedXMLElement firstChildElement() const override;

    std::shared_ptr<XMLAttribute> findAttribute(const std::string &name) const override;

    SharedXMLElement nextSiblingElement(const std::string &name) const override;

    SharedXMLElement nextSiblingElement() const override;

    std::vector<SharedXMLElement> children() const override;

    std::vector<SharedXMLElement> children(const std::string &name) const override;
  private:
    const tinyxml2::XMLElement &xmlElement_;
  };
}




