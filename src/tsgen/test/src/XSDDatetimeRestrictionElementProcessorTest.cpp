#include <gtest/gtest.h>
#include <XSDStringRestrictionElementProcessor.h>
#include <XSDDecimalRestrictionElementProcessor.h>
#include <XSDIntegerRestrictionElementProcessor.h>
#include <XSDDatetimeRestrictionElementProcessor.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"
#include "XSDSimpleTypeElementProcessor.h"
#include "mocks/MockEnumerationsProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDDatetimeRestrictionElementProcessor : public ::testing::Test {
protected:
  void SetUp() override {
    processor = new tsgen::XSDDatetimeRestrictionElementProcessor();
  }

  void TearDown() override {
    delete processor;
  }
  tsgen::XSDDatetimeRestrictionElementProcessor* processor;
};

TEST_F (
    XSDDatetimeRestrictionElementProcessor, shouldReturnEmptyIfBaseIsNotDatetime) {
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("xs:restriction"));
  EXPECT_CALL(*mockXMlElement, findAttribute("base"))
      .Times(1)
      .WillOnce(Return(mockXMLAttr));
  EXPECT_CALL(*mockXMLAttr, value())
      .Times(1)
      .WillOnce(Return("xs:something"));

  EXPECT_EQ(processor->process(mockXMlElement), "");
}

TEST_F (
    XSDDatetimeRestrictionElementProcessor, shouldReturnString) {
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("xs:restriction"));
  EXPECT_CALL(*mockXMlElement, findAttribute("base"))
      .Times(1)
      .WillOnce(Return(mockXMLAttr));
  EXPECT_CALL(*mockXMLAttr, value())
      .Times(1)
      .WillOnce(Return("xs:dateTime"));
  EXPECT_EQ(processor->process(mockXMlElement), "string");
}
