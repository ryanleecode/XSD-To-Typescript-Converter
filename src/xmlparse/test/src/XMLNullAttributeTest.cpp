#include <gtest/gtest.h>
#include "../../src/XMLAttribute/XMLNullAttribute.h"

class XMLNullAttributeTest : public ::testing::Test {
protected:
  void SetUp() override {
    xmlNullAttribute = new xmlparse::XMLNullAttribute();
  }

  void TearDown() override {
    delete xmlNullAttribute;
  }

  xmlparse::XMLNullAttribute* xmlNullAttribute;
};

TEST_F (XMLNullAttributeTest, shouldNotHaveAValue) {
  EXPECT_EQ(xmlNullAttribute->hasValue(), false);
}

TEST_F (XMLNullAttributeTest, nameShouldReturnNullOpt) {
  EXPECT_EQ(xmlNullAttribute->value(), "");
}
