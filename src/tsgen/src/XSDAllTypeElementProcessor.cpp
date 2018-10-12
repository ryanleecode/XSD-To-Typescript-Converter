#include <XSDAllTypeElementProcessor.h>
#include <sstream>

tsgen::XSDAllTypeElementProcessor::XSDAllTypeElementProcessor(
    const util::PascalCaseTextProcessor &pascalCaseTextProcessor,
    const PrimitiveTypeMap &primitiveTypeMap
): pascalCaseTextProcessor_(pascalCaseTextProcessor), primitiveTypeMap_(primitiveTypeMap) {
}

std::string tsgen::XSDAllTypeElementProcessor::process(
    const tsgen::SharedXMLElement &element
) const {
  if (element->name() != "all") {
    return "";
  }
  std::stringstream text;
  auto children = element->children("element");
  for (const auto &child : children) {
    auto elementType = child->findAttribute("type")->value();
    auto simpleType = this->primitiveTypeMap_.find(elementType);
    if (simpleType != this->primitiveTypeMap_.end()) {
      elementType = simpleType->second;
    } else {
      this->pascalCaseTextProcessor_.process(elementType);
    }

    auto elementName = child->findAttribute("name")->value();

    auto minOccurencesValue = child->findAttribute("minOccurs")->value();
    auto isChildOptional = minOccurencesValue == "0";

    text << "\t";
    text << "\"";
    text << elementName;
    text << "\"";
    if (isChildOptional) {
      text << "?";
    }
    text << " : ";
    text << elementType;
    text << ";\n";
  }
  return text.str();
}




