#pragma once

#include <string>
#include <XMLElement.h>

namespace tsgen {
  typedef std::shared_ptr<xmlparse::XMLElement> SharedXMLElement;

  class XSDElementProcessor {
  public:
    virtual ~XSDElementProcessor() = default;

    virtual std::string process(const SharedXMLElement &element) const = 0;
  };
}
