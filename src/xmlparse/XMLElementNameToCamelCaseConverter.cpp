#include "XMLElementNameToCamelCaseConverter.h"

xmlparse::XMLElementNameToCamelCaseConverter::XMLElementNameToCamelCaseConverter(
    const std::string &name
) {
  auto formattedName = name;
  boost::trim(formattedName);
  std::vector<std::string> strs;
  boost::split(strs, formattedName, boost::is_any_of("-,_"));
  for (unsigned int i = 0; i < strs.size(); i += 1) {
    strs[i][0] = (unsigned char) toupper(strs[i][0]);
  }
  this->name_ = boost::algorithm::join(strs, "");
}

std::string xmlparse::XMLElementNameToCamelCaseConverter::getCamelCaseName() {
  return this->name_;
}
