#include "XMLNullElement.h"
#include "../XMLAttribute/XMLNullAttribute.h"

std::optional<std::string> xmlparse::XMLNullElement::name() const {
  return std::nullopt;
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLNullElement::firstChildElement(const std::string &name) const {
  return std::make_unique<xmlparse::XMLNullElement>();
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLNullElement::firstChildElement() const {
  return std::make_unique<xmlparse::XMLNullElement>();
}

std::unique_ptr<xmlparse::XMLAttribute> xmlparse::XMLNullElement::findAttribute(const std::string &name) const {
  return std::make_unique<xmlparse::XMLNullAttribute>();
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLNullElement::nextSiblingElement(const std::string &name) const {
  return std::make_unique<xmlparse::XMLNullElement>();
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLNullElement::nextSiblingElement() const {
  return std::make_unique<xmlparse::XMLNullElement>();
}