#pragma once
#include <string>
#include "XMLElement.h"
#include <memory>

namespace xmlparse {
  class XMLAttribute {
  public:
    virtual ~XMLAttribute() = default;

    virtual std::string value() const = 0;
  };
}