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

int main(int argc, char const *argv[]) {
  tinyxml2::XMLDocument doc;
  doc.LoadFile("Elements.xsd");

  tsgen::XSDStringEnumerationsProcessor xsdStringEnumerationsProcessor;

  tsgen::SharedXSDElementProcessors simpleTypeProcessors = {
      std::make_shared<tsgen::XSDStringRestrictionElementProcessor>(
          xsdStringEnumerationsProcessor),
      std::make_shared<tsgen::XSDIntegerRestrictionElementProcessor>(),
      std::make_shared<tsgen::XSDDecimalRestrictionElementProcessor>()
  };

  tsgen::SharedXSDElementProcessors subprocessors = {
      std::make_shared<tsgen::XSDSimpleTypeElementProcessor>(
          simpleTypeProcessors)
  };
  tsgen::XSDToTypescriptParseTree xsdToTypescriptParseTree(subprocessors);
  std::shared_ptr<xmlparse::XMLElement> xmlElementPtr(
      new xmlparse::XMLElementAdapter(*doc.RootElement()));
  std::cout << xsdToTypescriptParseTree.process(xmlElementPtr) << std::endl;

  return 0;
}
