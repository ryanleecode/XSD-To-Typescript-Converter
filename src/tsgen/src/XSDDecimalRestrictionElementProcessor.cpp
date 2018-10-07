
#include <XSDDecimalRestrictionElementProcessor.h>

std::string tsgen::XSDDecimalRestrictionElementProcessor::postProcess(
    const tsgen::SharedXMLElement &element
) const {
  if (element->findAttribute("base")->value() == "xs:decimal") {
    return "number";
  }
  return std::__cxx11::string();
}
