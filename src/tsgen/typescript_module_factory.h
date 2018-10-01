#pragma once

#include <bits/unique_ptr.h>
#include "typescript_module.h"
#include "../xmlparse/XMLElement.h"

namespace tsgen {
  class TypeScriptModuleFactory {
  public:
    TypeScriptModuleFactory() = default;

    const std::unique_ptr<TypeScriptModule> createTypescriptModule(
        const xmlparse::XMLElement &xmlElement
    ) const;

  private:
    void checkIfElementHasXsSchemaName(const xmlparse::XMLElement &xmlElement) const;

    void checkIfElementHasAttrNameXmlns(const xmlparse::XMLElement &xmlElement) const;
  };
}