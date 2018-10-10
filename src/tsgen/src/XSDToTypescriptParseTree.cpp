#include <sstream>
#include <vector>
#include "XSDToTypescriptParseTree.h"

tsgen::XSDToTypescriptParseTree::XSDToTypescriptParseTree(
    SharedXSDElementProcessors &subProcessors
) : XSDElementProcessorImp(subProcessors) {}

std::string tsgen::XSDToTypescriptParseTree::process(
    const SharedXMLElement &rootElement
) const {
  std::stringstream typescriptSchema;
  typescriptSchema << "/* tslint:disable */\n";
  typescriptSchema << XSDElementProcessorImp::process(rootElement);
  return typescriptSchema.str();
}


