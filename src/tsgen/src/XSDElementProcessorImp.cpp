#include <sstream>
#include <XSDElementProcessorImp.h>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/classification.hpp>

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

std::string tsgen::XSDElementProcessorImp::convertStringToPascalCase(
    const std::string &str
) const {
  std::string trimmedName = str;
  boost::trim(trimmedName);
  std::vector<std::string> strs;
  boost::split(strs, trimmedName, boost::is_any_of("-,_"));
  for (unsigned int i = 0; i < strs.size(); i += 1) {
    strs[i][0] = (unsigned char) toupper(strs[i][0]);
  }
  return boost::algorithm::join(strs, "");
}
