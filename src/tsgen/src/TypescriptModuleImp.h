#pragma once

#include <memory>
#include <vector>
#include <map>
#include <TypescriptModule.h>
#include "SimpleType.h"

namespace tsgen {
  typedef std::optional<std::string> OptString;
  typedef std::pair<OptString, std::unique_ptr<SimpleType>> SimpleTypePair;
  typedef std::vector<SimpleTypePair> SimpleTypes;

  class TypescriptModuleImp : public TypescriptModule {
  public:
    std::string generateTypescriptSchema() override;

    std::string getModuleName() const override;

  private:
    explicit TypescriptModuleImp(
        const std::string &moduleName,
        std::unique_ptr<SimpleTypes> simpleTypes);

    std::string moduleName_;
    std::unique_ptr<SimpleTypes> simpleTypes_;

    friend class TypescriptModuleFactory;
  };
}