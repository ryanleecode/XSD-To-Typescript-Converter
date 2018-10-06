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

    auto simpleTypes = std::make_unique<SimpleTypes>();

    auto currentElement = xmlElement.firstChildElement();
    while (currentElement->hasValue()) {
      if (std::string(currentElement->name().value()) == "xs:simpleType") {
        auto name = currentElement->findAttribute("name")->value();
        simpleTypes->push_back(SimpleTypePair(
            std::optional(name),
            std::make_unique<SimpleType>(*currentElement)
        ));
      }
      currentElement = currentElement->nextSiblingElement();
    }

    auto tsModuleName = requiredNameAttr->value().value();
    return std::unique_ptr<TypeScriptModule>(
        new TypeScriptModule(tsModuleName, std::move(simpleTypes)));
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

    if (!xmlElement.findAttribute(requiredAttributeName)->hasValue()) {
      throw xmlparse::MissingXMLAttributeException(requiredAttributeName);
    }
  }
}