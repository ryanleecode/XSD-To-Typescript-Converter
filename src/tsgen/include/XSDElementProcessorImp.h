#pragma once

#include <XSDElementProcessor.h>

namespace tsgen {
  typedef std::vector<std::shared_ptr<XSDElementProcessor>> SharedXSDElementProcessors;

  class XSDElementProcessorImp : public XSDElementProcessor {
  protected:
    ~XSDElementProcessorImp() override = 0;

    explicit XSDElementProcessorImp(SharedXSDElementProcessors &subProcessors);

    std::string process(const SharedXMLElement &element) const override;

    SharedXSDElementProcessors &subProcessors_;
  };

  inline XSDElementProcessorImp::~XSDElementProcessorImp() = default;
}




