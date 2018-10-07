#include <sstream>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/join.hpp>
#include "XSDSimpleTypeElementProcessor.h"

tsgen::XSDSimpleTypeElementProcessor::XSDSimpleTypeElementProcessor(
    tsgen::SharedXSDElementProcessors &subProcessors
) : XSDElementProcessorImp(subProcessors) {
}

std::string tsgen::XSDSimpleTypeElementProcessor::process(
    const tsgen::SharedXMLElement &element
) const {
  auto elementName = element->name();
  if (!elementName.has_value() || elementName.value() != "xs:simpleType") {
    return "";
  }
  auto typeName = element->findAttribute("name");
  if (!typeName->hasValue()) {
    return "";
  }

  std::stringstream text;
  text << "export type ";
  text << this->convertStringToPascalCase(typeName->value());
  text << " = ";
  text << XSDElementProcessorImp::process(element);
  text << ";\n";
  return text.str();
}

std::string tsgen::XSDSimpleTypeElementProcessor::convertStringToPascalCase(
    const std::string& str
) const {
  std::string trimmedName = str;
  boost::trim(trimmedName);
  std::vector<std::string> strs;
  boost::split(strs, trimmedName, boost::is_any_of("-,_"));
  for (unsigned int i = 0; i < strs.size(); i += 1) {
    strs[i][0] = (unsigned char) toupper(strs[i][0]);
  }
  return boost::algorithm::join(strs, "");
}
