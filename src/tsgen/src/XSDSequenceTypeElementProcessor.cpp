
#include <XSDSequenceTypeElementProcessor.h>
#include <sstream>

#include "XSDSequenceTypeElementProcessor.h"

std::string tsgen::XSDSequenceTypeElementProcessor::process(
    const tsgen::SharedXMLElement &element
) const {
  if (element->name() != "xs:sequence") {
    return "";
  }
  std::stringstream text;
  for (const auto& child : element->children("xs:element")) {
    text << "\"";
    text << child->findAttribute("name")->value();
    text << "\" : ";
    text << child->findAttribute("type")->value();
    text << ";\n";
  }
  return text.str();
}
