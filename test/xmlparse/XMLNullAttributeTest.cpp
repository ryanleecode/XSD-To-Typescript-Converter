#include <gtest/gtest.h>
#include "../../src/xmlparse/XMLElement/XMLNullElement.h"
#include "../../src/xmlparse/XMLAttribute/XMLNullAttribute.h"

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

TEST_F (XMLNullAttributeTest, nameShouldReturnNullOpt) {
  EXPECT_EQ(xmlNullAttribute->value(), std::nullopt);
}
