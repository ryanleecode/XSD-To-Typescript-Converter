#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../../../src/SimpleType.h"

namespace tsgen {
  class MockSimpleType : public SimpleType {
  public:
    MOCK_CONST_METHOD0(toTypescriptDefinition, std::string());
  };
}