#include <cstring>
#include <sstream>
#include "typescript_module.h"
#include "../xmlparse/incorrect_xml_element_name_exception.h"
#include "../xmlparse/missing_xml_attribute_exception.h"

const std::string requiredAttributeName = "xmlns";

namespace tsgen {
  const std::unique_ptr<TypeScriptModule> TypeScriptModule::Factory::create(
      const tinyxml2::XMLElement &xmlElement
  ) const {
    this->checkIfElementHasXsSchemaName(xmlElement);
    this->checkIfElementHasAttrNameXmlns(xmlElement);

    auto element = xmlElement.FindAttribute(requiredAttributeName.c_str());

    return std::unique_ptr<TypeScriptModule>((new TypeScriptModule(element->Value())));
  }

  void TypeScriptModule::Factory::checkIfElementHasXsSchemaName(
      const tinyxml2::XMLElement &xmlElement
  ) const {
    std::string elementName(xmlElement.Name());
    auto schemaElementName = "xs:schema";
    if (elementName != schemaElementName) {
      throw xmlparse::IncorrectXMLElementNameException(
          elementName,
          schemaElementName
      );
    }
  }

  void TypeScriptModule::Factory::checkIfElementHasAttrNameXmlns(
      const tinyxml2::XMLElement &xmlElement
  ) const {

    if (xmlElement.FindAttribute(requiredAttributeName.c_str()) == nullptr) {
      throw xmlparse::MissingXMLAttributeException(requiredAttributeName);
    }
  }
}