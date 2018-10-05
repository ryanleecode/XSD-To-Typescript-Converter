#include <gtest/gtest.h>
#include "../../src/xmlparse/XMLElement/XMLNullElement.h"
#include "../../src/xmlparse/XMLAttribute/XMLNullAttribute.h"

class XMLNullElementTest : public ::testing::Test {
protected:
  void SetUp() override {
    xmlNullElement = new xmlparse::XMLNullElement();
  }

  void TearDown() override {
    delete xmlNullElement;
  }

  xmlparse::XMLNullElement* xmlNullElement;
};

TEST_F (XMLNullElementTest, nameShouldReturnNullOpt) {
  EXPECT_EQ(xmlNullElement->name(), std::nullopt);
}

TEST_F (XMLNullElementTest, firstChildElementShouldReturnXMLNullElement) {
  auto childElement = xmlNullElement->firstChildElement();
  EXPECT_NO_THROW(dynamic_cast<xmlparse::XMLNullElement&>(*childElement));

  auto childElementParam1 = xmlNullElement->firstChildElement("");
  EXPECT_NO_THROW(dynamic_cast<xmlparse::XMLNullElement&>(*childElementParam1));
}

TEST_F (XMLNullElementTest, nextSiblingElementShouldReturnXMLNullElement) {
  auto siblingElement = xmlNullElement->nextSiblingElement();
  EXPECT_NO_THROW(dynamic_cast<xmlparse::XMLNullElement&>(*siblingElement));

  auto siblingElementParam1 = xmlNullElement->nextSiblingElement("");
  EXPECT_NO_THROW(dynamic_cast<xmlparse::XMLNullElement&>(*siblingElementParam1));
}

TEST_F (XMLNullElementTest, findAttributeShouldReturnXMLNullAttribute) {
  auto attribute = xmlNullElement->findAttribute("");
  EXPECT_NO_THROW(dynamic_cast<xmlparse::XMLNullAttribute&>(*attribute));
}