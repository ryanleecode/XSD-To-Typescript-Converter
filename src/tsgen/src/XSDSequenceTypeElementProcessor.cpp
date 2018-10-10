
#include <XSDSequenceTypeElementProcessor.h>
#include <sstream>
#include <unordered_map>

const std::unordered_map<std::string, std::string> simpleTypeMap = {
    {"string",   "string"},
    {"int",      "number"},
    {"decimal",  "number"},
    {"dateTime", "string"}
};

tsgen::XSDSequenceTypeElementProcessor::XSDSequenceTypeElementProcessor(
    const util::PascalCaseTextProcessor &pascalCaseTextProcessor
) : pascalCaseTextProcessor_(pascalCaseTextProcessor) {
}

std::string tsgen::XSDSequenceTypeElementProcessor::process(
    const tsgen::SharedXMLElement &element
) const {
  if (element->name() != "sequence") {
    return "";
  }
  std::stringstream text;
  for (const auto &child : element->children("element")) {
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
