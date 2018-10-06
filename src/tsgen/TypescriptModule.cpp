#include <sstream>
#include "TypescriptModule.h"

tsgen::TypeScriptModule::TypeScriptModule(
    const std::string &moduleName,
    std::unique_ptr<SimpleTypes> simpleTypes
) : moduleName_(moduleName), simpleTypes_(std::move(simpleTypes)) {
}

std::string tsgen::TypeScriptModule::getModuleName() const {
  return this->moduleName_;
}

std::string tsgen::TypeScriptModule::generateTypescriptSchema() {
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
