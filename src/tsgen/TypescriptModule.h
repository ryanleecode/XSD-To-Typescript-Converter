#pragma once

#include <memory>
#include <vector>
#include <map>
#include "tinyxml2.h"
#include "SimpleType.h"

namespace tsgen {
  typedef std::optional<std::string> OptString;
  typedef std::pair<OptString, std::unique_ptr<ISimpleType>> SimpleTypePair;
  typedef std::vector<SimpleTypePair> SimpleTypes;

  class TypeScriptModule {
  public:
    std::string generateTypescriptSchema();

    std::string getModuleName() const;

  private:
    explicit TypeScriptModule(
        const std::string &moduleName,
        std::unique_ptr<SimpleTypes> simpleTypes);

    std::string moduleName_;
    std::unique_ptr<SimpleTypes> simpleTypes_;

    friend class TypeScriptModuleFactory;
  };
}