
#include <XSDStringRestrictionElementProcessor.h>

#include "XSDStringRestrictionElementProcessor.h"

tsgen::XSDStringRestrictionElementProcessor::XSDStringRestrictionElementProcessor(
    const tsgen::XSDEnumerationsProcessor &enumerationsProcessor
) : enumerationsProcessor_(enumerationsProcessor) {
}

std::string tsgen::XSDStringRestrictionElementProcessor::postProcess(
    const tsgen::SharedXMLElement &element
) const {
  if (element->findAttribute("base")->value() != "xs:string") {
    return "";
  }
  if (!element->firstChildElement("xs:enumeration")->hasValue()) {
    return "string";
  }
  auto values = element->children("xs:enumeration");
  return enumerationsProcessor_.process(values);
}

