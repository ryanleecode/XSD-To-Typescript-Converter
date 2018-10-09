#pragma once

#include <XSDElementProcessor.h>

namespace tsgen {
  typedef std::vector<std::shared_ptr<XSDElementProcessor>> SharedXSDElementProcessors;

  class XSDElementProcessorImp : public XSDElementProcessor {
  public:
    std::string process(const SharedXMLElement &element) const override;
  protected:
    ~XSDElementProcessorImp() override = 0;

    explicit XSDElementProcessorImp(SharedXSDElementProcessors &subProcessors);

    std::string convertStringToPascalCase(const std::string &str) const;

    SharedXSDElementProcessors &subProcessors_;
  };

  inline XSDElementProcessorImp::~XSDElementProcessorImp() = default;
}




