#pragma once

#include "gmock/gmock.h"
#include "../../../src/xmlparse/XMLAttribute/XMLAttribute.h"

namespace xmlparse {
  class MockXMLAttribute : public XMLAttribute {
  public:
    MOCK_CONST_METHOD0(value, std::optional<std::string>());
  };
}