#pragma once
#include <string>
#include <optional>

namespace xmlparse {
  class XMLAttribute {
  public:
    virtual ~XMLAttribute() = default;

    virtual bool hasValue() const = 0;

    virtual std::string value() const = 0;
  };
}

