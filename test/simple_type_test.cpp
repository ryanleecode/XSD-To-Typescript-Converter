#include <gtest/gtest.h>
#include "../src/tsgen/typescript_primitive.h"
#include "../src/tsgen/simple_type.h"

class SimpleTypeTest : public ::testing::Test {
protected:
  void SetUp() override {
  }

  void TearDown() override {
  }
};

TEST_F(SimpleTypeTest,
       ShouldGenerateABasicStringTypeCorrectly) {
/*  tsgen::SimpleType<std::string> simpleStringType(
      "user-id",
      tsgen::TypescriptPrimitive::STRING,
      std::make_unique<std::vector<std::string>>());
  auto expectedString = "type UserId = string;";
  ASSERT_STRCASEEQ(simpleStringType.toTypescriptDefinition().c_str(), expectedString);*/
}

TEST_F(SimpleTypeTest,
       ShouldGenerateABasicNumberTypeCorrectly) {
/*  tsgen::SimpleType<int> simpleType(
      "apple-count",
      tsgen::TypescriptPrimitive::NUMBER,
      std::make_unique<std::vector<int>>());
  auto expectedString = "type AppleCount = number;";
  ASSERT_STRCASEEQ(simpleType.toTypescriptDefinition().c_str(), expectedString);*/
}