#pragma once

#include <XSDElementProcessor.h>
#include <unordered_map>
#include <PascalCaseTextProcessor.h>

namespace tsgen {
  typedef std::unordered_map<std::string, std::string> PrimitiveTypeMap;

  class XSDAllTypeElementProcessor : public XSDElementProcessor {
  public:
    explicit XSDAllTypeElementProcessor(
        const util::PascalCaseTextProcessor& pascalCaseTextProcessor,
        const PrimitiveTypeMap &primitiveTypeMap);

    std::string process(const SharedXMLElement &element) const override;

  private:
    const util::PascalCaseTextProcessor& pascalCaseTextProcessor_;

    const PrimitiveTypeMap &primitiveTypeMap_;
  };
}
