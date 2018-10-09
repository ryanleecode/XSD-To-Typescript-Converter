#include <iostream>
#include <tinyxml2.h>
#include <XMLElementAdapter.h>
#include <XSDToTypescriptParseTree.h>
#include <XSDSimpleTypeElementProcessor.h>
#include <XSDRestrictionElementProcessor.h>
#include <XSDStringRestrictionElementProcessor.h>
#include <XSDEnumerationsProcessorImp.h>
#include <XSDStringEnumerationsProcessor.h>
#include <XSDDecimalRestrictionElementProcessor.h>
#include <XSDIntegerRestrictionElementProcessor.h>
#include <XSDDatetimeRestrictionElementProcessor.h>
#include <XSDComplexTypeElementProcessor.h>
#include <PascalCaseTextProcessorImp.h>
#include <XSDSequenceTypeElementProcessor.h>

int main(int argc, char const *argv[]) {
  tinyxml2::XMLDocument doc;
  doc.LoadFile("Elements.xsd");

  tsgen::XSDStringEnumerationsProcessor xsdStringEnumerationsProcessor;

  tsgen::SharedXSDElementProcessors simpleTypeSubProcessors = {
      std::make_shared<tsgen::XSDStringRestrictionElementProcessor>(
          xsdStringEnumerationsProcessor),
      std::make_shared<tsgen::XSDIntegerRestrictionElementProcessor>(),
      std::make_shared<tsgen::XSDDecimalRestrictionElementProcessor>(),
      std::make_shared<tsgen::XSDDatetimeRestrictionElementProcessor>()
  };

  util::PascalCaseTextProcessorImp pascalCaseTextProcessorImp;
  tsgen::SharedXSDElementProcessors complexTypeSubProcessors = {
      std::make_shared<tsgen::XSDSequenceTypeElementProcessor>(pascalCaseTextProcessorImp)
  };

  tsgen::SharedXSDElementProcessors subprocessors = {
      std::make_shared<tsgen::XSDSimpleTypeElementProcessor>(
          simpleTypeSubProcessors),
      std::make_shared<tsgen::XSDComplexTypeElementProcessor>(complexTypeSubProcessors)
  };
  tsgen::XSDToTypescriptParseTree xsdToTypescriptParseTree(subprocessors);
  std::shared_ptr<xmlparse::XMLElement> xmlElementPtr(
      new xmlparse::XMLElementAdapter(*doc.RootElement()));
  std::cout << xsdToTypescriptParseTree.process(xmlElementPtr) << std::endl;

  return 0;
}
