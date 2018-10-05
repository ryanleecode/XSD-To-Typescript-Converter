#include "XMLElementAdapter.h"
#include "../XMLAttribute/XMLAttributeAdapter.h"
#include "XMLNullElement.h"
#include "../XMLAttribute/XMLNullAttribute.h"

xmlparse::XMLElementAdapter::XMLElementAdapter(
    const tinyxml2::XMLElement &xmlElement
) : xmlElement_(xmlElement) {
}

std::optional<std::string> xmlparse::XMLElementAdapter::name() const {
  return xmlElement_.Name()
         ? std::optional(std::string(xmlElement_.Name()))
         : std::nullopt;
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementAdapter::firstChildElement(
    const std::string &name
) const {

  const auto rawXMLElement = xmlElement_.FirstChildElement(name.c_str());

  if (rawXMLElement == nullptr) {
    return std::make_unique<xmlparse::XMLNullElement>();
  }

  return std::make_unique<xmlparse::XMLElementAdapter>(*rawXMLElement);
}

std::unique_ptr<xmlparse::XMLAttribute> xmlparse::XMLElementAdapter::findAttribute(
    const std::string &name
) const {
  auto rawAttribute = xmlElement_.FindAttribute(name.c_str());

  if (rawAttribute == nullptr) {
    return std::make_unique<xmlparse::XMLNullAttribute>();
  }

  return std::make_unique<xmlparse::XMLAttributeAdapter>(*rawAttribute);
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementAdapter::nextSiblingElement(
    const std::string &name
) const {
  auto rawSibling = xmlElement_.NextSiblingElement(name.c_str());

  if (rawSibling == nullptr) {
    return std::make_unique<xmlparse::XMLNullElement>();
  }

  return std::make_unique<xmlparse::XMLElementAdapter>(*rawSibling);
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementAdapter::firstChildElement() const {
  auto rawFirstChild = xmlElement_.FirstChildElement();

  if (rawFirstChild == nullptr) {
    return std::make_unique<xmlparse::XMLNullElement>();
  }

  return std::make_unique<xmlparse::XMLElementAdapter>(*rawFirstChild);
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementAdapter::nextSiblingElement() const {
  auto rawNextSibling = xmlElement_.NextSiblingElement();

  if (rawNextSibling == nullptr) {
    return std::make_unique<xmlparse::XMLNullElement>();
  }

  return std::make_unique<xmlparse::XMLElementAdapter>(
      *rawNextSibling);
}

bool xmlparse::XMLElementAdapter::hasValue() const {
  return true;
}

