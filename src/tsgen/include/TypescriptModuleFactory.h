#pragma once

#include <memory>
#include <XMLElement.h>
#include "TypescriptModule.h"

namespace tsgen {
  class TypescriptModuleFactory {
  public:
    TypescriptModuleFactory() = default;

    const std::unique_ptr<TypescriptModule> createTypescriptModule(
        const xmlparse::XMLElement &xmlElement
    ) const;

  private:
    void checkIfElementHasXsSchemaName(const xmlparse::XMLElement &xmlElement) const;

    void checkIfElementHasAttrNameXmlns(const xmlparse::XMLElement &xmlElement) const;
  };
}
