#pragma once

#include <PascalCaseTextProcessor.h>
#include "XSDElementProcessorImp.h"

namespace tsgen {
  typedef std::vector<std::shared_ptr<XSDElementProcessor>> SharedXSDElementProcessors;
  typedef std::optional<std::string> OptionalString;

  class XSDSequenceTypeElementProcessor : public XSDElementProcessor {
  public:
    explicit XSDSequenceTypeElementProcessor(
        const util::PascalCaseTextProcessor &pascalCaseTextProcessor);

    std::string process(const SharedXMLElement &element) const override;

  private:
    const util::PascalCaseTextProcessor &pascalCaseTextProcessor_;
  };
}




