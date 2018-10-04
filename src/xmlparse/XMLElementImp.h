#pragma once

#include <tinyxml2.h>
#include "XMLElement.h"

namespace xmlparse {
  class XMLElementImp : public XMLElement {
  public:
    XMLElementImp(const tinyxml2::XMLElement &xmlElement);

    std::string name() const override;

    std::unique_ptr<XMLElement> firstChildElement(const std::string &name) const override;

    std::unique_ptr<XMLElement> firstChildElement() const override;

    std::unique_ptr<XMLElement> firstChildElement(const std::string &name) override;

    std::unique_ptr<XMLElement> firstChildElement() override;

    std::unique_ptr<XMLAttribute> findAttribute(const std::string &name) const override;

    std::unique_ptr<XMLElement> nextSiblingElement(const std::string &name) const override;

    std::unique_ptr<XMLElement> nextSiblingElement() const override;
  private:
    const tinyxml2::XMLElement &xmlElement_;
  };
}




