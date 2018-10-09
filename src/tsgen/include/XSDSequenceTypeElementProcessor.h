#pragma once

#include "XSDElementProcessorImp.h"

namespace tsgen {
  class XSDSequenceTypeElementProcessor : XSDElementProcessor {
  public:
    std::string process(const SharedXMLElement &element) const override;
  };
}




