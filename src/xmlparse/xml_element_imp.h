#pragma once

#include <tinyxml2.h>
#include "XMLElement.h"

namespace xmlparse {
  class XMLElementImp : public XMLElement {
  public:
    XMLElementImp(const tinyxml2::XMLElement &xmlElement);

    std::string name() const override;

    const std::shared_ptr<XMLElement> firstChildElement(const std::string &name) const override;

  private:
    const tinyxml2::XMLElement &xmlElement_;
  };
}




