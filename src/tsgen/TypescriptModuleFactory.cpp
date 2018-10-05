#include <cstring>
#include <sstream>
#include "TypescriptModule.h"
#include "../xmlparse/IncorrectXMLElementNameException.h"
#include "../xmlparse/MissingXMLAttributeException.h"
#include "TypescriptModuleFactory.h"


const std::string requiredAttributeName = "xmlns";

namespace tsgen {
  typedef std::unique_ptr<ISimpleType> UniqueSimpleType;
  typedef std::optional<std::string> OptString;

  const std::unique_ptr<TypeScriptModule> TypeScriptModuleFactory::createTypescriptModule(
      const xmlparse::XMLElement &xmlElement
  ) const {
    this->checkIfElementHasXsSchemaName(xmlElement);
    this->checkIfElementHasAttrNameXmlns(xmlElement);

    auto requiredNameAttr = xmlElement.findAttribute(requiredAttributeName);

    auto simpleTypes = std::make_unique<SimpleTypeMap>();

    auto currentElement = xmlElement.firstChildElement();
    while (currentElement != nullptr) {
      if (std::string(currentElement->name().value()) == "xs:simpleType") {
        auto name = currentElement->findAttribute("name")->value();
/*        auto type = std::string(currentElement
                                    ->firstChildElement("xs:restriction")
                                    ->findAttribute("base")
                                    ->value());*/
        simpleTypes->insert(std::pair<OptString, UniqueSimpleType>(
            std::optional(name),
            std::unique_ptr<ISimpleType>(new SimpleType<std::string>(*currentElement))
        ));
      }
      currentElement = currentElement->nextSiblingElement();
    }

    return std::unique_ptr<TypeScriptModule>(
        new TypeScriptModule(requiredNameAttr->value().value(), std::move(simpleTypes)));
  }

  void TypeScriptModuleFactory::checkIfElementHasXsSchemaName(
      const xmlparse::XMLElement &xmlElement
  ) const {
    std::string elementName(xmlElement.name().value());
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