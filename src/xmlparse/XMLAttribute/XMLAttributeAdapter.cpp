#include "XMLAttributeAdapter.h"

xmlparse::XMLAttributeAdapter::XMLAttributeAdapter(
    const tinyxml2::XMLAttribute &xmlAttribute
) : xmlAttribute_(xmlAttribute) {
}

std::optional<std::string> xmlparse::XMLAttributeAdapter::value() const {
  return xmlAttribute_.Value()
         ? std::optional(std::string(xmlAttribute_.Value()))
    : std::nullopt;
}

bool xmlparse::XMLAttributeAdapter::hasValue() const {
  return true;
}
