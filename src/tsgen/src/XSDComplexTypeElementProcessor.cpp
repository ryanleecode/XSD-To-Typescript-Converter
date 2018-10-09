
#include <XSDComplexTypeElementProcessor.h>
#include <sstream>

tsgen::XSDComplexTypeElementProcessor::XSDComplexTypeElementProcessor(
    tsgen::SharedXSDElementProcessors &subProcessors
) : XSDElementProcessorImp(subProcessors) {
}

std::string tsgen::XSDComplexTypeElementProcessor::process(
    const tsgen::SharedXMLElement &element
) const {
  auto elementName = element->name();
  if (elementName.value() != "xs:complexType") {
    return "";
  }
  auto typeName = element->findAttribute("name");

  std::stringstream text;
  text << "export interface ";
  text << this->convertStringToPascalCase(typeName->value());
  text << " {\n";
  text << XSDElementProcessorImp::process(element);
  text << "}\n";

  return text.str();
}
