#include "xml_element_imp.h"

xmlparse::XMLElementImp::XMLElementImp(
    const tinyxml2::XMLElement &xmlElement
): xmlElement_(xmlElement) {
}

std::string xmlparse::XMLElementImp::name() const {
  return xmlElement_.Name();
}

const std::shared_ptr<xmlparse::XMLElement> xmlparse::XMLElementImp::firstChildElement(
    const std::string &name
) const {
  const auto rawXMLElement = xmlElement_.FirstChildElement(name.c_str());
  return std::make_shared<xmlparse::XMLElementImp>(rawXMLElement);
}

