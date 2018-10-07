#include <gtest/gtest.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"
#include "XSDSimpleTypeElementProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDSimpleTypeElementProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {

  }

  void TearDown() override {
  }
};

TEST_F (
    XSDSimpleTypeElementProcessorTest, shouldReturnEmptyStringWhenNameIsEmpty) {
  tsgen::SharedXSDElementProcessors subProcessors;
  tsgen::XSDSimpleTypeElementProcessor simpleTypeElementProcessor(subProcessors);
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("xs:simpleType"));
  EXPECT_CALL(*mockXMLAttr, hasValue())
      .Times(1)
      .WillOnce(Return(false));
  EXPECT_CALL(*mockXMlElement, findAttribute("name"))
      .Times(1)
      .WillOnce(Return(mockXMLAttr));
  EXPECT_EQ(simpleTypeElementProcessor.process(mockXMlElement), "");
}

TEST_F (
    XSDSimpleTypeElementProcessorTest, shouldReturnEmptyStringWhenNameIsNotSimpleType) {
  tsgen::SharedXSDElementProcessors subProcessors;
  tsgen::XSDSimpleTypeElementProcessor simpleTypeElementProcessor(subProcessors);
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("xs:complexType"));
  EXPECT_EQ(simpleTypeElementProcessor.process(mockXMlElement), "");
}

TEST_F (
    XSDSimpleTypeElementProcessorTest, shouldProcessSimpleTypeCorrectly) {
  tsgen::SharedXSDElementProcessors subProcessors;
  tsgen::XSDSimpleTypeElementProcessor simpleTypeElementProcessor(subProcessors);
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("xs:simpleType"));
  EXPECT_CALL(*mockXMlElement, findAttribute("name"))
      .Times(1)
      .WillOnce(Return(mockXMLAttr));

  EXPECT_CALL(*mockXMLAttr, hasValue())
      .Times(1)
      .WillOnce(Return(true));
  EXPECT_CALL(*mockXMLAttr, value())
      .Times(1)
      .WillOnce(Return("response-code"));

  EXPECT_EQ(simpleTypeElementProcessor.process(mockXMlElement),
      "export type ResponseCode = ;\n");
}
