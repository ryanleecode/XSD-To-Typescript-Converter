
#include <XSDStringRestrictionElementProcessor.h>

tsgen::XSDStringRestrictionElementProcessor::XSDStringRestrictionElementProcessor(
    const tsgen::XSDEnumerationsProcessor &enumerationsProcessor
) : enumerationsProcessor_(enumerationsProcessor) {
}

std::string tsgen::XSDStringRestrictionElementProcessor::postProcess(
    const tsgen::SharedXMLElement &element
) const {
  if (element->findAttribute("base")->value() != "string") {
    return "";
  }
  if (!element->firstChildElement("enumeration")->hasValue()) {
    return "string";
  }
  auto values = element->children("enumeration");
  return enumerationsProcessor_.process(values);
}

