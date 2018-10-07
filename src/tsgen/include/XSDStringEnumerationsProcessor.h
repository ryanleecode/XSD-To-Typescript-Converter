#pragma once

#include "XSDEnumerationsProcessorImp.h"

namespace tsgen {
  class XSDStringEnumerationsProcessor : public XSDEnumerationsProcessorImp {
  protected:
    std::string processEnumerationElement(SharedXMLElement enumeration) const override;
  };
}




