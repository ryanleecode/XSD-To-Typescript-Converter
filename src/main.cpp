#include <iostream>
#include <tinyxml2.h>
#include <XMLElementAdapter.h>
#include <XSDToTypescriptParseTree.h>
#include <XSDSimpleTypeElementProcessor.h>
#include <XSDRestrictionElementProcessor.h>
#include <XSDStringRestrictionElementProcessor.h>
#include <XSDEnumerationsProcessorImp.h>
#include <XSDStringEnumerationsProcessor.h>

int main(int argc, char const *argv[]) {
/*
    CLI::App app("K3Pi goofit fitter");

    std::string file;
    CLI::Option *opt = app.add_option("-f,--file,file", file, "File name");

    int count;
    CLI::Option *copt = app.add_option("-c,--count", count, "Counter");

    int v;
    CLI::Option *flag = app.add_flag("--flag", v, "Some flag that can be passed multiple times");

    double value; // = 3.14;
    app.add_option("-d,--double", value, "Some Value");

    CLI11_PARSE(app, argc, argv);

    std::cout << "Working on file: " << file << ", direct count: " << app.count("--file")
              << ", opt count: " << opt->count() << std::endl;
    std::cout << "Working on count: " << count << ", direct count: " << app.count("--count")
              << ", opt count: " << copt->count() << std::endl;
    std::cout << "Received flag: " << v << " (" << flag->count() << ") times\n";
    std::cout << "Some value: " << value << std::endl;
*/
  tinyxml2::XMLDocument doc;
  doc.LoadFile("Elements.xsd");

  tsgen::XSDStringEnumerationsProcessor xsdStringEnumerationsProcessor;
  auto stringRestrictionProcessor =
      std::make_shared<tsgen::XSDStringRestrictionElementProcessor>(
          xsdStringEnumerationsProcessor);

  tsgen::SharedXSDElementProcessors simpleTypeProcessors;
  simpleTypeProcessors.push_back(stringRestrictionProcessor);
  auto simpleTypeElementProcessor = std::make_shared<tsgen::XSDSimpleTypeElementProcessor>(
      simpleTypeProcessors);

  tsgen::SharedXSDElementProcessors subprocessors;
  subprocessors.push_back(simpleTypeElementProcessor);
  tsgen::XSDToTypescriptParseTree xsdToTypescriptParseTree(subprocessors);
  std::shared_ptr<xmlparse::XMLElement> xmlElementPtr(
      new xmlparse::XMLElementAdapter(*doc.RootElement()));
  std::cout << xsdToTypescriptParseTree.process(xmlElementPtr) << std::endl;

  return 0;
}
