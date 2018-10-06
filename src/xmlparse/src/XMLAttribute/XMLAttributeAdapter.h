#pragma once

#include <tinyxml2.h>
#include <XMLAttribute.h>

namespace xmlparse {
  class XMLAttributeAdapter : public XMLAttribute {
  public:
    XMLAttributeAdapter(const tinyxml2::XMLAttribute &xmlAttribute);

    bool hasValue() const override;

    std::optional<std::string> value() const override;

  private:
    const tinyxml2::XMLAttribute& xmlAttribute_;
  };
}




