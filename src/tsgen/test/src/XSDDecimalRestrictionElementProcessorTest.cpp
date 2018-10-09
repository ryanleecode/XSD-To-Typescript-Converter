#include <gtest/gtest.h>
#include <XSDStringRestrictionElementProcessor.h>
#include <XSDDecimalRestrictionElementProcessor.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"
#include "XSDSimpleTypeElementProcessor.h"
#include "mocks/MockEnumerationsProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDDecimalRestrictionProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {

  }

  void TearDown() override {
  }
};

TEST_F (
    XSDDecimalRestrictionProcessorTest, shouldReturnEmptyIfBaseIsNotDecimal) {
  tsgen::XSDDecimalRestrictionElementProcessor decimalRestrictionElementProcessor;
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

  EXPECT_EQ(decimalRestrictionElementProcessor.process(mockXMlElement), "");
}

TEST_F (
    XSDDecimalRestrictionProcessorTest, shouldReturnNumber) {
  tsgen::XSDDecimalRestrictionElementProcessor decimalRestrictionElementProcessor;
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
      .WillOnce(Return("decimal"));
  EXPECT_EQ(decimalRestrictionElementProcessor.process(mockXMlElement), "number");
}
