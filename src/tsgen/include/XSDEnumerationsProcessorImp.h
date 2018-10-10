#pragma once

#include "XSDEnumerationsProcessor.h"

namespace tsgen {
  class XSDEnumerationsProcessorImp : public XSDEnumerationsProcessor {
  public:
    std::string process(const std::vector<SharedXMLElement>& enumerations) const override;

  protected:
    virtual std::string processEnumerationElement(SharedXMLElement enumeration) const;
  };
}




