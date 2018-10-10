#pragma once

#include "XSDRestrictionElementProcessor.h"

namespace tsgen {
  class XSDIntegerRestrictionElementProcessor : public XSDRestrictionElementProcessor {
  public:
    std::string postProcess(const SharedXMLElement &element) const override;
  };
}




