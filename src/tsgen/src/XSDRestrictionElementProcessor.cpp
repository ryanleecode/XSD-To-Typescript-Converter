
#include <XSDRestrictionElementProcessor.h>
#include <sstream>

std::string tsgen::XSDRestrictionElementProcessor::process(
    const tsgen::SharedXMLElement &element
) const {
  if (this->preProcess(element) == std::nullopt) {
    return "";
  }
  return this->postProcess(element);
}

tsgen::OptionalString tsgen::XSDRestrictionElementProcessor::preProcess(
    const tsgen::SharedXMLElement &element
) const {
  if (element->name() != "xs:restriction") {
    return std::nullopt;
  }
  return "";
}
