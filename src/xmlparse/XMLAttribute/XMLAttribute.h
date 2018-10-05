#pragma once
#include <string>
#include <optional>
#include <memory>

namespace xmlparse {
  class XMLAttribute {
  public:
    virtual ~XMLAttribute() = default;

    virtual std::optional<std::string> value() const = 0;
  };
}