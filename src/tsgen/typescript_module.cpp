#include "typescript_module.h"

tsgen::TypeScriptModule::TypeScriptModule(
    const std::string &moduleName
) {
  moduleName_ = moduleName;
}

std::string tsgen::TypeScriptModule::getModuleName() const {
  return this->moduleName_;
}
