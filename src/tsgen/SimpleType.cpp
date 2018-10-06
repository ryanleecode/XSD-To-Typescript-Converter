#include <sstream>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <tinyxml2.h>
#include "SimpleType.h"
#include "../xmlparse/XMLElementNameToCamelCaseConverter.h"
#include "../xmlparse/MissingXMLAttributeException.h"
#include "restrictions/StringRestrictionHandler.h"

const std::string NAME = "name";

namespace tsgen {
  SimpleType::SimpleType(
      const xmlparse::XMLElement &simpleTypeElement
  ) {

    auto nameAttr = simpleTypeElement.findAttribute(NAME);
    if (nameAttr == nullptr) {
      throw xmlparse::MissingXMLAttributeException(NAME);
    }
    auto rawName = std::string(nameAttr->value().value());
    this->name_ = xmlparse::XMLElementNameToCamelCaseConverter(rawName).getCamelCaseName();

    auto restrictionElement = simpleTypeElement.firstChildElement("xs:restriction");
    auto restriction = restrictionElement->findAttribute("base");
    auto restrictionValue = restriction->value();
    auto base = restrictionValue.value();

    StringRestrictionHandler(this->type_, this->possibleValues_)
        .handle(base, std::vector<RestrictionPair>());
    if (base == "xs:int") {
      this->type_ = "number";
    }
  }

  std::string SimpleType::toTypescriptDefinition() const {
    std::stringstream tsDefBuilder;
    tsDefBuilder << "type "
                 << this->name_
                 << " = "
                 << this->type_
                 << ";";

    return tsDefBuilder.str();
  }
}

