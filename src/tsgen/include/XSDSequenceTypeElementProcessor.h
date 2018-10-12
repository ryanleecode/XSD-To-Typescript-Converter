#pragma once

#include <PascalCaseTextProcessor.h>
#include <unordered_map>
#include "XSDElementProcessorImp.h"

namespace tsgen {
  typedef std::vector<std::shared_ptr<XSDElementProcessor>> SharedXSDElementProcessors;
  typedef std::optional<std::string> OptionalString;
  typedef std::unordered_map<std::string, std::string> PrimitiveTypeMap;

  class XSDSequenceTypeElementProcessor : public XSDElementProcessor {
  public:
    explicit XSDSequenceTypeElementProcessor(
        const util::PascalCaseTextProcessor &pascalCaseTextProcessor,
        const PrimitiveTypeMap &primitiveTypeMap);

    std::string process(const SharedXMLElement &element) const override;

  private:
    const util::PascalCaseTextProcessor &pascalCaseTextProcessor_;

    const PrimitiveTypeMap &primitiveTypeMap_;
  };
}




