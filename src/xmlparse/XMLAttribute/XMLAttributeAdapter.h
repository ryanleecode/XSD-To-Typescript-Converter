#pragma once

#include "XMLAttribute.h"

#include <tinyxml2.h>

namespace xmlparse {
  class XMLAttributeAdapter : public XMLAttribute {
  public:
    XMLAttributeAdapter(const tinyxml2::XMLAttribute &xmlAttribute);

    std::optional<std::string> value() const override;

  private:
    const tinyxml2::XMLAttribute& xmlAttribute_;
  };
}




