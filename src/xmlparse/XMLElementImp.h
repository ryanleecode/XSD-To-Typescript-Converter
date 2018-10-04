#pragma once

#include <tinyxml2.h>
#include "XMLElement.h"

namespace xmlparse {
  class XMLElementImp : public XMLElement {
  public:
    XMLElementImp(const tinyxml2::XMLElement &xmlElement);

    std::string name() const override;

    std::shared_ptr<XMLElement> firstChildElement(const std::string &name) const override;

    std::shared_ptr<XMLElement> firstChildElement() const override;

    std::shared_ptr<XMLElement> firstChildElement(const std::string &name) override;

    std::shared_ptr<XMLElement> firstChildElement() override;

    std::shared_ptr<XMLAttribute> findAttribute(const std::string &name) const override;

    std::shared_ptr<XMLElement> nextSiblingElement(const std::string &name) const override;

    std::shared_ptr<XMLElement> nextSiblingElement() const override;
  private:
    const tinyxml2::XMLElement &xmlElement_;
  };
}




