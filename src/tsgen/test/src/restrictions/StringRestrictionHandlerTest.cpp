#include <gtest/gtest.h>
#include "../../../src/restrictions/StringRestrictionHandler.h"

class StringRestrictionHandlerTest : public ::testing::Test {
protected:
  void SetUp() override {
  }

  void TearDown() override {
  }
};

TEST_F(StringRestrictionHandlerTest, shouldHandleAStringType) {
  std::string restriction;
  tsgen::StringRestrictionHandler handler(restriction);
  std::string base = "xs:string";
  tsgen::RestrictionPairs restrictionPairs;

  handler.handle(base, restrictionPairs);

  EXPECT_EQ(restriction, "string");
}

TEST_F(StringRestrictionHandlerTest, shouldIgnoreNonStringTypes) {
  std::string restriction;
  tsgen::StringRestrictionHandler handler(restriction);
  std::string base = "xs:int";
  tsgen::RestrictionPairs restrictionPairs;

  handler.handle(base, restrictionPairs);

  EXPECT_EQ(restriction, "");
}