#pragma once

#include <memory>
#include "tinyxml2.h"

namespace tsgen {
  class TypeScriptModule {
  public:
    class Factory {
    public:
      Factory() = default;

      const std::unique_ptr<TypeScriptModule> create(const tinyxml2::XMLElement &xmlElement) const;

    private:
      void checkIfElementHasXsSchemaName(const tinyxml2::XMLElement &xmlElement) const;

      void
      checkIfElementHasAttrNameXmlns(const tinyxml2::XMLElement &xmlElement) const;
    };

    std::string getModuleName() const;

  private:
    explicit TypeScriptModule(const std::string &moduleName);

    std::string moduleName_;
  };
}