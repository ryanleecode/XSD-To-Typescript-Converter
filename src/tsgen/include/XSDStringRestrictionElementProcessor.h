#pragma once

#include "XSDRestrictionElementProcessor.h"
#include "XSDEnumerationsProcessor.h"

namespace tsgen {
  class XSDStringRestrictionElementProcessor : public XSDRestrictionElementProcessor {
  public:
    explicit XSDStringRestrictionElementProcessor(
        const XSDEnumerationsProcessor &enumerationsProcessor);

  protected:
    std::string postProcess(const SharedXMLElement &element) const override;

  private:
    const XSDEnumerationsProcessor &enumerationsProcessor_;
  };
}




