#include <gtest/gtest.h>
#include <XSDStringRestrictionElementProcessor.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"
#include "XSDSimpleTypeElementProcessor.h"
#include "mocks/MockEnumerationsProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDStringRestrictionProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {

  }

  void TearDown() override {
  }
};

TEST_F (
    XSDStringRestrictionProcessorTest, shouldReturnEmptyIfBaseIsNotString) {
  tsgen::MockXSDEnumerationsProcessor enumerationProcessor;
  tsgen::XSDStringRestrictionElementProcessor stringRestrictionElementProcessor(
      enumerationProcessor);
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("restriction"));
  EXPECT_CALL(*mockXMlElement, findAttribute("base"))
      .Times(1)
      .WillOnce(Return(mockXMLAttr));
  EXPECT_CALL(*mockXMLAttr, value())
      .Times(1)
      .WillOnce(Return("int"));

  EXPECT_EQ(stringRestrictionElementProcessor.process(mockXMlElement), "");
}

TEST_F (
    XSDStringRestrictionProcessorTest, shouldReturnStringIfLacksChildEnumeration) {
  tsgen::MockXSDEnumerationsProcessor enumerationProcessor;
  tsgen::XSDStringRestrictionElementProcessor stringRestrictionElementProcessor(
      enumerationProcessor);
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("restriction"));
  EXPECT_CALL(*mockXMlElement, findAttribute("base"))
      .Times(1)
      .WillOnce(Return(mockXMLAttr));
  EXPECT_CALL(*mockXMLAttr, value())
      .Times(1)
      .WillOnce(Return("string"));

  auto enumerationElement = std::make_shared<xmlparse::MockXMLElement>();
  EXPECT_CALL(*mockXMlElement, firstChildElement("enumeration"))
    .Times(1)
    .WillOnce(Return(enumerationElement));
  EXPECT_CALL(*enumerationElement, hasValue())
    .Times(1)
    .WillOnce(Return(false));

  EXPECT_EQ(stringRestrictionElementProcessor.process(mockXMlElement), "string");
}
