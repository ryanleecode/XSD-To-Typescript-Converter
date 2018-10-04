#include "XMLElementImp.h"
#include "XMLAttributeImp.h"

xmlparse::XMLElementImp::XMLElementImp(
    const tinyxml2::XMLElement &xmlElement
) : xmlElement_(xmlElement) {
}

std::string xmlparse::XMLElementImp::name() const {
  return xmlElement_.Name() == nullptr ? std::string() : xmlElement_.Name();
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementImp::firstChildElement(
    const std::string &name
) const {

  const auto rawXMLElement = xmlElement_.FirstChildElement(name.c_str());

  if (rawXMLElement == nullptr) {
    return nullptr;
  }

  return std::make_unique<xmlparse::XMLElementImp>(*rawXMLElement);
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementImp::firstChildElement(
    const std::string &name
) {
  const auto rawXMLElement = xmlElement_.FirstChildElement(name.c_str());

  if (rawXMLElement == nullptr) {
    return nullptr;
  }

  return std::make_unique<xmlparse::XMLElementImp>(*rawXMLElement);
}

std::unique_ptr<xmlparse::XMLAttribute> xmlparse::XMLElementImp::findAttribute(
    const std::string &name
) const {
  auto rawAttribute = xmlElement_.FindAttribute(name.c_str());

  if (rawAttribute == nullptr) {
    return nullptr;
  }

  return std::make_unique<xmlparse::XMLAttributeImp>(*rawAttribute);
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementImp::nextSiblingElement(
    const std::string &name
) const {
  auto rawSibling = xmlElement_.NextSiblingElement(name.c_str());

  if (rawSibling == nullptr) {
    return nullptr;
  }

  return std::make_unique<xmlparse::XMLElementImp>(*rawSibling);
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementImp::firstChildElement() const {
  auto rawFirstChild = xmlElement_.FirstChildElement();

  if (rawFirstChild == nullptr) {
    return nullptr;
  }

  return std::make_unique<xmlparse::XMLElementImp>(*rawFirstChild);
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementImp::firstChildElement() {
  auto rawFirstChild = xmlElement_.FirstChildElement();

  if (rawFirstChild == nullptr) {
    return nullptr;
  }

  return std::make_unique<xmlparse::XMLElementImp>(*rawFirstChild);
}

std::unique_ptr<xmlparse::XMLElement> xmlparse::XMLElementImp::nextSiblingElement() const {
  auto rawNextSibling = xmlElement_.NextSiblingElement();

  if (rawNextSibling == nullptr) {
    return nullptr;
  }

  return std::make_unique<xmlparse::XMLElementImp>(
      *rawNextSibling);
}

