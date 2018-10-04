#include <sstream>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <tinyxml2.h>
#include "SimpleType.h"
#include "../xmlparse/XMLElementNameToCamelCaseConverter.h"

namespace tsgen {
  template<typename T>
  SimpleType<T>::SimpleType(
      const xmlparse::XMLElement &simpleTypeElement
  ) {

    auto rawName = std::string(simpleTypeElement.findAttribute("name")->value());
    this->name_ = xmlparse::XMLElementNameToCamelCaseConverter(rawName).getCamelCaseName();
  }

  template<typename T>
  std::string SimpleType<T>::toTypescriptDefinition() const {
    std::stringstream tsDefBuilder;
    tsDefBuilder << "type "
                 << this->name_
                 << " = "
                 << (this->type_ == TypescriptPrimitive::STRING ? "string" : "number")
                 << ";";

    return tsDefBuilder.str();
  }
}

