#include <gtest/gtest.h>
#include "../src/tsgen/xsd_primitive.h"
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
  tsgen::SimpleType<std::string> simpleStringType(
      "user-id",
      tsgen::XSDPrimitive::STRING,
      std::make_unique<std::vector<std::string>>());
  auto expectedString = "type UserId = string;";
  ASSERT_STRCASEEQ(simpleStringType.toTypescriptDefinition().c_str(), expectedString);

  tsgen::SimpleType<std::string> simpleStringType_2(
      "friendship-indicator-field",
      tsgen::XSDPrimitive::STRING,
      std::make_unique<std::vector<std::string>>());
  auto expectedString_2 = "type FriendshipIndicatorField = string;";
  ASSERT_STRCASEEQ(simpleStringType_2.toTypescriptDefinition().c_str(), expectedString_2);
}

TEST_F(SimpleTypeTest,
       ShouldGenerateABasicNumberTypeCorrectly) {
  tsgen::SimpleType<int> simpleType(
      "user-id",
      tsgen::XSDPrimitive::NUMBER,
      std::make_unique<std::vector<int>>());
  auto expectedString = "type UserId = string;";
  ASSERT_STRCASEEQ(simpleType.toTypescriptDefinition().c_str(), expectedString);

  tsgen::SimpleType<std::string> simpleType_2(
      "friendship-indicator-field",
      tsgen::XSDPrimitive::STRING,
      std::make_unique<std::vector<std::string>>());
  auto expectedString_2 = "type FriendshipIndicatorField = string;";
  ASSERT_STRCASEEQ(simpleType_2.toTypescriptDefinition().c_str(), expectedString_2);
}