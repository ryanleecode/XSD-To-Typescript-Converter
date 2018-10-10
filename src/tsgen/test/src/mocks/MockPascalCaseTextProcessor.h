#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <PascalCaseTextProcessor.h>

namespace util {
  class MockPascalCaseTextProcessor : public PascalCaseTextProcessor {
  public:
    MOCK_CONST_METHOD1(process, void(std::string&));
  };
}