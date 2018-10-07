#pragma once

#include <XMLElement.h>

namespace tsgen {
  typedef std::shared_ptr<xmlparse::XMLElement> SharedXMLElement;

  class XSDEnumerationsProcessor {
  public:
    virtual ~XSDEnumerationsProcessor() = 0;

    virtual std::string process(const std::vector<SharedXMLElement>& enumerations) const = 0;
  };

  inline XSDEnumerationsProcessor::~XSDEnumerationsProcessor() = default;
}




