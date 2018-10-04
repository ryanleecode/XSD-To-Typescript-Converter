#include "XMLAttributeImp.h"

xmlparse::XMLAttributeImp::XMLAttributeImp(
    const tinyxml2::XMLAttribute &xmlAttribute
) : xmlAttribute_(xmlAttribute) {
}

std::optional<std::string> xmlparse::XMLAttributeImp::value() const {
  return xmlAttribute_.Name()
    ? std::optional(std::string(xmlAttribute_.Name()))
    : std::nullopt;
}
