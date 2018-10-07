
#include <XSDIntegerRestrictionElementProcessor.h>

std::string tsgen::XSDIntegerRestrictionElementProcessor::postProcess(
    const tsgen::SharedXMLElement &element
) const {
  if (element->findAttribute("base")->value() == "xs:int") {
    return "number";
  }
  return std::__cxx11::string();
}
