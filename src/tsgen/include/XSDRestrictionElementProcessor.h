#pragma once

#include <XSDElementProcessor.h>

namespace tsgen {
  typedef std::optional<std::string> OptionalString;

  class XSDRestrictionElementProcessor : public XSDElementProcessor {
  public:
    ~XSDRestrictionElementProcessor() override = default;

    std::string process(const SharedXMLElement &element) const final;


  protected:
    virtual std::string postProcess(const SharedXMLElement &element) const = 0;

  private:
    OptionalString preProcess(const SharedXMLElement &element) const;
  };
}




