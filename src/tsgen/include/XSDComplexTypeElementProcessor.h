#pragma once

#include "XSDElementProcessorImp.h"

namespace tsgen {
  class XSDComplexTypeElementProcessor : public XSDElementProcessorImp {
  public:
    explicit XSDComplexTypeElementProcessor(SharedXSDElementProcessors &subProcessors);

    std::string process(const SharedXMLElement &element) const override;
  };
}




