#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <XMLAttribute.h>

namespace xmlparse {
  class MockXMLAttribute : public XMLAttribute {
  public:
    MOCK_CONST_METHOD0(hasValue, bool());

    MOCK_CONST_METHOD0(value, std::string());
  };
}
