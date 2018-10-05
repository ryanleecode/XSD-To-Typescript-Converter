#include "XMLAttributeAdapter.h"

xmlparse::XMLAttributeAdapter::XMLAttributeAdapter(
    const tinyxml2::XMLAttribute &xmlAttribute
) : xmlAttribute_(xmlAttribute) {
}

std::optional<std::string> xmlparse::XMLAttributeAdapter::value() const {
  return xmlAttribute_.Name()
    ? std::optional(std::string(xmlAttribute_.Name()))
    : std::nullopt;
}
