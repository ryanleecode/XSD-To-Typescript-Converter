#pragma once

#include <tinyxml2.h>
#include <XMLAttribute.h>

namespace xmlparse {
  class XMLAttributeAdapter : public XMLAttribute {
  public:
    explicit XMLAttributeAdapter(const tinyxml2::XMLAttribute &xmlAttribute);

    bool hasValue() const override;

    std::string value() const override;

  private:
    const tinyxml2::XMLAttribute& xmlAttribute_;
  };
}




