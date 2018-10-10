#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <XSDElementProcessor.h>

namespace tsgen {
  class MockXSDElementProcessor : public XSDElementProcessor {
  public:
    MockXSDElementProcessor() = default;

    explicit MockXSDElementProcessor(const MockXSDElementProcessor &processor) = default;

    MOCK_CONST_METHOD1(process, std::string(const SharedXMLElement &element));
  };
}