#include <sstream>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "simple_type.h"

namespace tsgen {
  template<typename T>
  SimpleType<T>::SimpleType(
      const std::string &name,
      XSDPrimitive type,
      std::unique_ptr<std::vector<T>> possibleValues
  ): type_(type), possibleValues_(std::move(possibleValues)) {

    auto formattedName = name;
    boost::trim(formattedName);
    std::vector<std::string> strs;
    boost::split(strs, formattedName, boost::is_any_of("-,_"));
    for (unsigned int i = 0; i < strs.size(); i += 1) {
      strs[i][0] = (unsigned char) toupper(strs[i][0]);
    }

    this->name_ = boost::algorithm::join(strs, "");
  }

  template<typename T>
  std::string SimpleType<T>::toTypescriptDefinition() const {
    std::stringstream tsDefBuilder;
    tsDefBuilder << "type "
                 << this->name_
                 << " = "
                 << "string"
                 << ";";

    return tsDefBuilder.str();
  }
}

