#include <sstream>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <XMLElement.h>
#include <MissingXMLAttributeException.h>
#include <XMLElementNameToCamelCaseConverter.h>
#include <restrictions/NumberRestrictionHandler.h>
#include "SimpleTypeImp.h"
#include "restrictions/StringRestrictionHandler.h"

const std::string NAME = "name";

namespace tsgen {
  SimpleTypeImp::SimpleTypeImp(
      const xmlparse::XMLElement &simpleTypeElement
  ) {

    auto nameAttr = simpleTypeElement.findAttribute(NAME);
    if (nameAttr == nullptr) {
      throw xmlparse::MissingXMLAttributeException(NAME);
    }
    auto rawName = std::string(nameAttr->value().value());
    this->name_ = xmlparse::XMLElementNameToCamelCaseConverter(rawName)
        .getCamelCaseName();

    auto restrictionElement = simpleTypeElement.firstChildElement("xs:restriction");
    auto restriction = restrictionElement->findAttribute("base");
    auto restrictionValue = restriction->value();
    auto base = restrictionValue.value();

    auto restrictionPairs = RestrictionPairs();
    auto restrictionDefinitionElement = restrictionElement->firstChildElement();
    while (restrictionDefinitionElement->hasValue()) {
      auto restrictionDefinitionName = restrictionDefinitionElement->name();
      auto restrictionDefinitionValueElement =
          restrictionDefinitionElement->findAttribute("value");
      auto restrictionDefinitionValue = restrictionDefinitionValueElement->value();

      if (restrictionDefinitionValue.has_value()) {
        restrictionPairs.insert(
            {restrictionDefinitionName.value(), restrictionDefinitionValue.value()}
        );
        restrictionDefinitionElement = restrictionDefinitionElement->nextSiblingElement();
      }
    }

    StringRestrictionHandler(this->type_)
        .handle(base, restrictionPairs);
    NumberRestrictionHandler(this->type_)
        .handle(base, restrictionPairs);
  }

  std::string SimpleTypeImp::toTypescriptDefinition() const {
    std::stringstream tsDefBuilder;
    tsDefBuilder << "type "
                 << this->name_
                 << " = "
                 << this->type_
                 << ";";

    return tsDefBuilder.str();
  }
}

