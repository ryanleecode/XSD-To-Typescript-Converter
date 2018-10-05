#pragma once
#include "XMLAttribute.h"

#include <tinyxml2.h>

namespace xmlparse {
  class XMLAttributeImp : public XMLAttribute {
  public:
    XMLAttributeImp(const tinyxml2::XMLAttribute& xmlAttribute);

    std::optional<std::string> value() const override;

  private:
    const tinyxml2::XMLAttribute& xmlAttribute_;
  };
}




