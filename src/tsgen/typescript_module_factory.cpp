#include <cstring>
#include <sstream>
#include "typescript_module.h"
#include "../xmlparse/incorrect_xml_element_name_exception.h"
#include "../xmlparse/missing_xml_attribute_exception.h"
#include "typescript_module_factory.h"


const std::string requiredAttributeName = "xmlns";

namespace tsgen {
  const std::unique_ptr<TypeScriptModule> TypeScriptModuleFactory::createTypescriptModule(
      const xmlparse::XMLElement &xmlElement
  ) const {
    this->checkIfElementHasXsSchemaName(xmlElement);
    this->checkIfElementHasAttrNameXmlns(xmlElement);

    auto element = xmlElement.findAttribute(requiredAttributeName);

    auto simpleTypes = std::make_unique<SimpleTypeMap>();

    auto currentElement = xmlElement.firstChildElement();
    while (currentElement != nullptr) {
      if (std::string(currentElement->name()) == "xs:simpleType") {
        auto name = currentElement->findAttribute("name")->value();
        auto type = std::string(currentElement
                                    ->firstChildElement("xs:restriction")
                                    ->findAttribute("base")
                                    ->value());
        simpleTypes->insert(std::pair<std::string, std::unique_ptr<ISimpleType>>(
            name,
            std::unique_ptr<ISimpleType>(new SimpleType<std::string>(*currentElement))
        ));
      }
      currentElement = currentElement->nextSiblingElement();
    }

    return std::unique_ptr<TypeScriptModule>(
        new TypeScriptModule(element->value(), std::move(simpleTypes)));
  }

  void TypeScriptModuleFactory::checkIfElementHasXsSchemaName(
      const xmlparse::XMLElement &xmlElement
  ) const {
    std::string elementName(xmlElement.name());
    auto schemaElementName = "xs:schema";
    if (elementName != schemaElementName) {
      throw xmlparse::IncorrectXMLElementNameException(
          elementName,
          schemaElementName
      );
    }
  }

  void TypeScriptModuleFactory::checkIfElementHasAttrNameXmlns(
      const xmlparse::XMLElement &xmlElement
  ) const {

    if (xmlElement.findAttribute(requiredAttributeName) == nullptr) {
      throw xmlparse::MissingXMLAttributeException(requiredAttributeName);
    }
  }
}