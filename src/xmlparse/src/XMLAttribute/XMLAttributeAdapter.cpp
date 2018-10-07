#include "XMLAttributeAdapter.h"

xmlparse::XMLAttributeAdapter::XMLAttributeAdapter(
    const tinyxml2::XMLAttribute &xmlAttribute
) : xmlAttribute_(xmlAttribute) {
}

std::string xmlparse::XMLAttributeAdapter::value() const {
  return xmlAttribute_.Value()
         ? std::string(xmlAttribute_.Value())
         : "";
}

bool xmlparse::XMLAttributeAdapter::hasValue() const {
  return true;
}
