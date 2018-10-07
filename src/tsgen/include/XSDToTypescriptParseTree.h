#pragma once

#include <string>
#include <XMLElement.h>
#include <vector>
#include "XSDElementProcessor.h"
#include "XSDElementProcessorImp.h"

namespace tsgen {
  class XSDToTypescriptParseTree : public XSDElementProcessorImp {
  public:
    explicit XSDToTypescriptParseTree(SharedXSDElementProcessors &subProcessors);

    std::string process(
        const SharedXMLElement &rootElement
    ) const override;
  };
}




