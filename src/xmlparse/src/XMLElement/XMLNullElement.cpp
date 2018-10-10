#include "XMLNullElement.h"
#include "../XMLAttribute/XMLNullAttribute.h"

std::optional<std::string> xmlparse::XMLNullElement::name() const {
  return std::nullopt;
}

std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLNullElement::firstChildElement(const std::string &name) const {
  return std::make_shared<xmlparse::XMLNullElement>();
}

std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLNullElement::firstChildElement() const {
  return std::make_shared<xmlparse::XMLNullElement>();
}

std::shared_ptr<xmlparse::XMLAttribute> xmlparse::XMLNullElement::findAttribute(const std::string &name) const {
  return std::make_shared<xmlparse::XMLNullAttribute>();
}

std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLNullElement::nextSiblingElement(const std::string &name) const {
  return std::make_shared<xmlparse::XMLNullElement>();
}

std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLNullElement::nextSiblingElement() const {
  return std::make_shared<xmlparse::XMLNullElement>();
}

bool xmlparse::XMLNullElement::hasValue() const {
  return false;
}

std::vector<xmlparse::XMLElement::SharedXMLElement> xmlparse::XMLNullElement::children() const {
  return std::vector<xmlparse::XMLElement::SharedXMLElement>();
}

std::vector<xmlparse::XMLElement::SharedXMLElement> xmlparse::XMLNullElement::children(const std::string &name) const {
  return std::vector<xmlparse::XMLElement::SharedXMLElement>();
}
