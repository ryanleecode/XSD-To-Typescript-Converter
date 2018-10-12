
#include <XSDSequenceTypeElementProcessor.h>
#include <sstream>
#include <unordered_map>

tsgen::XSDSequenceTypeElementProcessor::XSDSequenceTypeElementProcessor(
    const util::PascalCaseTextProcessor &pascalCaseTextProcessor,
    const PrimitiveTypeMap& primitiveTypeMap
) : pascalCaseTextProcessor_(pascalCaseTextProcessor), primitiveTypeMap_(primitiveTypeMap) {
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

    auto simpleType = this->primitiveTypeMap_.find(type);
    if (simpleType != this->primitiveTypeMap_.end()) {
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
