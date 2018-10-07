#include <sstream>
#include <XSDElementProcessorImp.h>

tsgen::XSDElementProcessorImp::XSDElementProcessorImp(
    tsgen::SharedXSDElementProcessors &subProcessors
): subProcessors_(subProcessors) {
}

std::string tsgen::XSDElementProcessorImp::process(
    const tsgen::SharedXMLElement& element
) const {
  std::stringstream processedText;
  auto children = element->children();
  for (const auto &child : children) {
    for (auto &processor : this->subProcessors_) {
      processedText << processor->process(child);
    }
  }
  return processedText.str();
}
