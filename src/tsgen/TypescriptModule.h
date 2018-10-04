#pragma once

#include <memory>
#include <vector>
#include <map>
#include "tinyxml2.h"
#include "SimpleType.h"

namespace tsgen {
  typedef std::map<std::string, std::unique_ptr<ISimpleType>> SimpleTypeMap;

  class TypeScriptModule {
  public:

    std::string generateTypescriptSchema();

    std::string getModuleName() const;

  private:
    explicit TypeScriptModule(
        const std::string &moduleName,
        std::unique_ptr<SimpleTypeMap> simpleTypes);

    std::string moduleName_;
    std::unique_ptr<SimpleTypeMap> simpleTypes_;

    friend class TypeScriptModuleFactory;
  };
}