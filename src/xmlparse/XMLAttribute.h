#pragma once
#include <string>
#include <memory>

namespace xmlparse {
  class XMLAttribute {
  public:
    virtual ~XMLAttribute() = default;

    virtual std::string value() const = 0;
  };
}