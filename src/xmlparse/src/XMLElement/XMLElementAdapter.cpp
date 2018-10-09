
#include <XMLElementAdapter.h>
#include <XMLElementAdapter.h>
#include <XMLAttribute/XMLNullAttribute.h>
#include <XMLAttribute/XMLAttributeAdapter.h>
#include "XMLNullElement.h"

xmlparse::XMLElementAdapter::XMLElementAdapter(
    const tinyxml2::XMLElement &xmlElement
) : xmlElement_(xmlElement) {
}

std::optional<std::string> xmlparse::XMLElementAdapter::name() const {
  if (xmlElement_.Name() == nullptr) {
    return std::nullopt;
  }
  auto removeCharsBeforeColon = [](std::string &str) {
    size_t position = str.find(':');
    str = str.substr(position + 1);
  };
  auto name = std::string(xmlElement_.Name());
  removeCharsBeforeColon(name);
  return std::optional(name);
}

std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLElementAdapter::firstChildElement(
    const std::string &name
) const {

  const auto rawXMLElement = xmlElement_.FirstChildElement(name.c_str());

  if (rawXMLElement == nullptr) {
    return std::make_shared<xmlparse::XMLNullElement>();
  }

  return std::make_shared<xmlparse::XMLElementAdapter>(*rawXMLElement);
}

std::shared_ptr<xmlparse::XMLAttribute> xmlparse::XMLElementAdapter::findAttribute(
    const std::string &name
) const {
  auto rawAttribute = xmlElement_.FindAttribute(name.c_str());

  if (rawAttribute == nullptr) {
    return std::make_shared<xmlparse::XMLNullAttribute>();
  }

  return std::make_shared<xmlparse::XMLAttributeAdapter>(*rawAttribute);
}

std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLElementAdapter::nextSiblingElement(
    const std::string &name
) const {
  auto rawSibling = xmlElement_.NextSiblingElement(name.c_str());

  if (rawSibling == nullptr) {
    return std::make_shared<xmlparse::XMLNullElement>();
  }

  return std::make_shared<xmlparse::XMLElementAdapter>(*rawSibling);
}

std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLElementAdapter::firstChildElement() const {
  auto rawFirstChild = xmlElement_.FirstChildElement();

  if (rawFirstChild == nullptr) {
    return std::make_shared<xmlparse::XMLNullElement>();
  }

  return std::make_shared<xmlparse::XMLElementAdapter>(*rawFirstChild);
}

std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLElementAdapter::nextSiblingElement() const {
  auto rawNextSibling = xmlElement_.NextSiblingElement();

  if (rawNextSibling == nullptr) {
    return std::make_shared<xmlparse::XMLNullElement>();
  }

  return std::make_shared<xmlparse::XMLElementAdapter>(
      *rawNextSibling);
}

bool xmlparse::XMLElementAdapter::hasValue() const {
  return true;
}

std::vector<xmlparse::XMLElement::SharedXMLElement> xmlparse::XMLElementAdapter::children() const {
  std::vector<xmlparse::XMLElement::SharedXMLElement> children;
  auto child = this->firstChildElement();
  while (child->hasValue()) {
    children.push_back(child);
    child = child->nextSiblingElement();
  }
  return children;
}

std::vector<xmlparse::XMLElement::SharedXMLElement>
xmlparse::XMLElementAdapter::children(const std::string &name) const {
  std::vector<xmlparse::XMLElement::SharedXMLElement> children;
  auto child = this->firstChildElement();
  while (child->hasValue()) {
    if (child->name().has_value() && child->name().value() == name) {
      children.push_back(child);
    }
    child = child->nextSiblingElement();
  }
  return children;
}

