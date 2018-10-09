
#include <XSDStringEnumerationsProcessor.h>

std::string
tsgen::XSDStringEnumerationsProcessor::processEnumerationElement(tsgen::SharedXMLElement enumeration) const {
  auto parsedResult = XSDEnumerationsProcessorImp::processEnumerationElement(enumeration);

  parsedResult.insert(0, "\"");
  parsedResult.append("\"");

  return parsedResult;
}
