
#include <XSDSequenceTypeElementProcessor.h>
#include <sstream>
#include <unordered_map>

const std::unordered_map<std::string, std::string> simpleTypeMap = {
    {"xs:string",   "string"},
    {"xs:int",      "number"},
    {"xs:decimal",  "number"},
    {"xs:dateTime", "string"}
};

tsgen::XSDSequenceTypeElementProcessor::XSDSequenceTypeElementProcessor(
    const util::PascalCaseTextProcessor &pascalCaseTextProcessor
) : pascalCaseTextProcessor_(pascalCaseTextProcessor) {
}

std::string tsgen::XSDSequenceTypeElementProcessor::process(
    const tsgen::SharedXMLElement &element
) const {
  if (element->name() != "xs:sequence") {
    return "";
  }
  std::stringstream text;
  for (const auto& child : element->children("xs:element")) {
    std::string type = child->findAttribute("type")->value();

    auto simpleType = simpleTypeMap.find(type);
    if (simpleType != simpleTypeMap.end()) {
      type = simpleType->second;
    } else {
      this->pascalCaseTextProcessor_.process(type);
    }
    text << "\t";
    text << "\"";
    text << child->findAttribute("name")->value();
    text << "\" : ";
    text << type;
    text << ";\n";
  }
  return text.str();
}
