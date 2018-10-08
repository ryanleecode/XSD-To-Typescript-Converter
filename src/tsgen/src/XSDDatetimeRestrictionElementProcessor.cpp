
#include <XSDDatetimeRestrictionElementProcessor.h>

#include "XSDDatetimeRestrictionElementProcessor.h"

std::string tsgen::XSDDatetimeRestrictionElementProcessor::postProcess(
    const tsgen::SharedXMLElement &element
) const {
  if (element->findAttribute("base")->value() == "xs:dateTime") {
    return "string";
  }
  return std::__cxx11::string();
}
