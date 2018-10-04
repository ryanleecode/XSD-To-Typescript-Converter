#include "XMLAttributeImp.h"

xmlparse::XMLAttributeImp::XMLAttributeImp(
    const tinyxml2::XMLAttribute &xmlAttribute
) : xmlAttribute_(xmlAttribute) {
}

std::string xmlparse::XMLAttributeImp::value() const {
  return xmlAttribute_.Name() == nullptr ? std::string() : xmlAttribute_.Name();
}
