#pragma once

#include <XMLAttribute.h>

namespace xmlparse {
  class XMLNullAttribute : public xmlparse::XMLAttribute {
  public:
    XMLNullAttribute() = default;

    bool hasValue() const override;

    std::string value() const override;
  };
}




