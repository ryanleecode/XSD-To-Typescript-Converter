#include <gtest/gtest.h>
#include "../../../src/tsgen/restrictions/StringRestrictionHandler.h"

class StringRestrictionHandlerTest : public ::testing::Test {
protected:
  void SetUp() override {
  }

  void TearDown() override {
  }
};

TEST_F(StringRestrictionHandlerTest, shouldHandleAStringType) {
  std::string restriction;
  tsgen::RestrictionUnion restrictionUnion;
  tsgen::StringRestrictionHandler handler(restriction, restrictionUnion);
  std::string base = "xs:string";
  std::vector<tsgen::RestrictionPair> restrictionPairs;

  handler.handle(base, restrictionPairs);

  EXPECT_EQ(restriction, "string");
  EXPECT_EQ(restrictionPairs.size(), 0);
}

TEST_F(StringRestrictionHandlerTest, shouldIgnoreNonStringTypes) {
  std::string restriction;
  tsgen::RestrictionUnion restrictionUnion;
  tsgen::StringRestrictionHandler handler(restriction, restrictionUnion);
  std::string base = "xs:int";
  std::vector<tsgen::RestrictionPair> restrictionPairs;

  handler.handle(base, restrictionPairs);

  EXPECT_EQ(restriction, "");
  EXPECT_EQ(restrictionPairs.size(), 0);
}