#include <gtest/gtest.h>
#include "../../../src/restrictions/NumberRestrictionHandler.h"

class NumberRestrictionHandlerTest : public ::testing::Test {
protected:
  void SetUp() override {
    restriction = new std::string();
    handler = new tsgen::NumberRestrictionHandler(*restriction);
  }

  void TearDown() override {
    delete restriction;
    delete handler;
  }

  std::string* restriction;
  tsgen::NumberRestrictionHandler* handler;
};

TEST_F(NumberRestrictionHandlerTest, shouldHandleAnIntType) {
  std::string base = "xs:int";
  tsgen::RestrictionPairs restrictionPairs;

  handler->handle(base, restrictionPairs);

  EXPECT_EQ(*restriction, "number");
}

TEST_F(NumberRestrictionHandlerTest, shouldHandleAnIntUnionType) {
  std::string base = "xs:int";
  tsgen::RestrictionPairs restrictionPairs = {
      {"xs:minInclusive", "1"},
      {"xs:maxInclusive", "5"}
  };

  handler->handle(base, restrictionPairs);

  EXPECT_EQ(*restriction, "1 | 2 | 3 | 4 | 5");
}

TEST_F(NumberRestrictionHandlerTest, shouldHandleADecimalType) {
  std::string base = "xs:decimal";
  tsgen::RestrictionPairs restrictionPairs;

  handler->handle(base, restrictionPairs);

  EXPECT_EQ(*restriction, "number");
}

TEST_F(NumberRestrictionHandlerTest, shouldIgnoreNonNumberType) {
  std::string base = "xs:not-a-number";
  tsgen::RestrictionPairs restrictionPairs;

  handler->handle(base, restrictionPairs);

  EXPECT_EQ(*restriction, "");
}
