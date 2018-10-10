#pragma once

#include <XSDElementProcessorImp.h>

namespace tsgen {
  class XSDSimpleTypeElementProcessor : public XSDElementProcessorImp {
  public:
    explicit XSDSimpleTypeElementProcessor(SharedXSDElementProcessors &subProcessors);

    std::string process(const SharedXMLElement &element) const override;
  };
};




