#include <gtest/gtest.h>
#include <XSDComplexTypeElementProcessor.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"
#include "XSDSimpleTypeElementProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDComplexTypeElementProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {

  }

  void TearDown() override {
  }
};

TEST_F (
    XSDComplexTypeElementProcessorTest, shouldReturnEmptyStringWhenNameIsComplexType) {
  tsgen::SharedXSDElementProcessors subProcessors;
  tsgen::XSDComplexTypeElementProcessor complexTypeElementProcessor(subProcessors);
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("simpleType"));
  EXPECT_EQ(complexTypeElementProcessor.process(mockXMlElement), "");
}

TEST_F (
    XSDComplexTypeElementProcessorTest, shouldProcessComplexTypeCorrectly) {
  tsgen::SharedXSDElementProcessors subProcessors;
  tsgen::XSDComplexTypeElementProcessor complexTypeElementProcessor(subProcessors);
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("complexType"));
  EXPECT_CALL(*mockXMlElement, findAttribute("name"))
      .Times(1)
      .WillOnce(Return(mockXMLAttr));

  EXPECT_CALL(*mockXMLAttr, value())
      .Times(1)
      .WillOnce(Return("flower-pot"));

  EXPECT_EQ(complexTypeElementProcessor.process(mockXMlElement),
            "export interface FlowerPot {\n}\n");
}
