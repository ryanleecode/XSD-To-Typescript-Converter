#pragma once

#include "XMLAttribute.h"

namespace xmlparse {
  class XMLNullAttribute : public xmlparse::XMLAttribute {
  public:
    XMLNullAttribute() = default;

    std::optional<std::string> value() const override;
  };
}




