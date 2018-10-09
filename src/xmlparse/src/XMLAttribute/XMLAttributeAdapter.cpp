#include "XMLAttributeAdapter.h"

xmlparse::XMLAttributeAdapter::XMLAttributeAdapter(
    const tinyxml2::XMLAttribute &xmlAttribute
) : xmlAttribute_(xmlAttribute) {
}

std::string xmlparse::XMLAttributeAdapter::value() const {
  if (xmlAttribute_.Value() == nullptr) {
    return "";
  }
  auto removeCharsBeforeColumn = [](std::string &str) {
    size_t position = str.find(':');
    str = str.substr(position + 1);
  };
  auto value = std::string(xmlAttribute_.Value());
  removeCharsBeforeColumn(value);
  return value;
}

bool xmlparse::XMLAttributeAdapter::hasValue() const {
  return true;
}
