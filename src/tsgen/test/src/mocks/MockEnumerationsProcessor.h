#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <XSDEnumerationsProcessor.h>

namespace tsgen {
  class MockXSDEnumerationsProcessor : public XSDEnumerationsProcessor {
  public:
    MOCK_CONST_METHOD1(process, std::string(
        const std::vector<SharedXMLElement>&));
  };
}