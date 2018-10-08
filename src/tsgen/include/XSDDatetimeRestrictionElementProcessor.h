#pragma once

#include "XSDRestrictionElementProcessor.h"

namespace tsgen {
  class XSDDatetimeRestrictionElementProcessor : public XSDRestrictionElementProcessor {
  public:
    std::string postProcess(const SharedXMLElement &element) const override;
  };
}




