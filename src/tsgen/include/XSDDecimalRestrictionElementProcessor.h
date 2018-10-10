#pragma once

#include "XSDRestrictionElementProcessor.h"

namespace tsgen {
  class XSDDecimalRestrictionElementProcessor : public XSDRestrictionElementProcessor {
  public:
    std::string postProcess(const SharedXMLElement &element) const override;
  };
}




