#include <sstream>
#include "TypescriptModuleImp.h"

tsgen::TypescriptModuleImp::TypescriptModuleImp(
    const std::string &moduleName,
    std::unique_ptr<SimpleTypes> simpleTypes
) : moduleName_(moduleName), simpleTypes_(std::move(simpleTypes)) {
}

std::string tsgen::TypescriptModuleImp::getModuleName() const {
  return this->moduleName_;
}

std::string tsgen::TypescriptModuleImp::generateTypescriptSchema() {
  std::stringstream typescriptSchema;
  typescriptSchema << "/* tslint:disable */\n";
  for (const auto &simpleType : *this->simpleTypes_) {
    auto &value = simpleType.second;
    typescriptSchema << "export "
                     << value->toTypescriptDefinition()
                     << "\n";
  }
  return typescriptSchema.str();
}
