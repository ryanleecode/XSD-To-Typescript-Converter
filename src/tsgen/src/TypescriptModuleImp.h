#pragma once

#include <memory>
#include <vector>
#include <map>
#include <TypescriptModule.h>
#include "SimpleType.h"

namespace tsgen {
  typedef std::vector<std::unique_ptr<SimpleType>> SimpleTypes;

  class TypescriptModuleImp : public TypescriptModule {
  public:
    explicit TypescriptModuleImp(
        const std::string &moduleName,
        std::unique_ptr<SimpleTypes> simpleTypes);

    std::string generateTypescriptSchema() override;

    std::string getModuleName() const override;

  private:
    std::string moduleName_;
    std::unique_ptr<SimpleTypes> simpleTypes_;

    friend class TypescriptModuleFactory;
  };
}