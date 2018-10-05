#include <iostream>
#include "tinyxml2.h"
#include "tsgen/TypescriptModule.h"
#include "xmlparse/IncorrectXMLElementNameException.h"
#include "tsgen/TypescriptModuleFactory.h"
#include "xmlparse/XMLElement/XMLElementAdapter.h"

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
  auto tsModule = tsgen::TypeScriptModuleFactory().createTypescriptModule(
      xmlparse::XMLElementAdapter(*doc.RootElement()));
  return 0;
}
