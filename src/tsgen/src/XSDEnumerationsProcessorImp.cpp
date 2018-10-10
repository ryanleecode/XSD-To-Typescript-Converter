
#include <XSDEnumerationsProcessorImp.h>
#include <string>
#include <sstream>
#include <iterator>
#include <experimental/iterator>
#include <algorithm>

std::string tsgen::XSDEnumerationsProcessorImp::process(
    const std::vector<tsgen::SharedXMLElement> &enumerations
) const {
  std::vector<std::string> enumerationValues;
  std::transform(
      enumerations.begin(), enumerations.end(), std::back_inserter(enumerationValues),
      [&](tsgen::SharedXMLElement element) {
        return this->processEnumerationElement(element);
      });
  std::ostringstream typeStream;
  std::copy(
      enumerationValues.begin(),
      enumerationValues.end(),
      std::experimental::make_ostream_joiner(typeStream, " | "));
  return typeStream.str();
}

std::string tsgen::XSDEnumerationsProcessorImp::processEnumerationElement(
    tsgen::SharedXMLElement enumeration
) const {
  auto valueAttr = enumeration->findAttribute("value");
  auto value = valueAttr->value();
  return value;
}
