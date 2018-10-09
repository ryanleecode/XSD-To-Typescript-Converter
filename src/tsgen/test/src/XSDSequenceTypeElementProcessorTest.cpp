#include <gtest/gtest.h>
#include <XSDSequenceTypeElementProcessor.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDSequenceTypeElementProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {

  }

  void TearDown() override {
  }
};

TEST_F (
    XSDSequenceTypeElementProcessorTest, shouldReturnEmptyStringIfNotASequenceType) {
  tsgen::XSDSequenceTypeElementProcessor sequenceTypeElementProcessor;
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("xs:someType"));
  EXPECT_EQ(sequenceTypeElementProcessor.process(mockXMlElement), "");
}

TEST_F (
    XSDSequenceTypeElementProcessorTest, shouldFilterOutChildrenThatAreNotElementTypes) {
  tsgen::XSDSequenceTypeElementProcessor sequenceTypeElementProcessor;
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("xs:sequence"));

  EXPECT_CALL(*mockXMlElement, children("xs:element"));
  sequenceTypeElementProcessor.process(mockXMlElement);
}

TEST_F (
    XSDSequenceTypeElementProcessorTest, shouldParseChildrenAsProperKeyValuePairs) {
  tsgen::XSDSequenceTypeElementProcessor sequenceTypeElementProcessor;
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("xs:sequence"));

  std::map<std::string, std::string> keyValuePairs = {
      { "friend-id", "friend-id" },
      { "location", "location" }
  };
  std::vector<tsgen::SharedXMLElement> children;
  for (const auto& pair: keyValuePairs) {
    auto element = std::make_shared<xmlparse::MockXMLElement>();
    EXPECT_CALL(*element, name())
      .WillOnce(Return("xs:element"));
    auto nameAttr = std::make_shared<xmlparse::MockXMLAttribute>();
    EXPECT_CALL(*nameAttr, value())
      .WillOnce(Return(pair.first));
    EXPECT_CALL(*element, findAttribute("name"))
      .WillOnce(Return(nameAttr));
    auto valueAttr = std::make_shared<xmlparse::MockXMLAttribute>();
    EXPECT_CALL(*valueAttr, value())
        .WillOnce(Return(pair.second));
    EXPECT_CALL(*element, findAttribute("type"))
        .WillOnce(Return(valueAttr));

    children.push_back(element);
  }

  EXPECT_CALL(*mockXMlElement, children("xs:element"))
    .WillOnce(Return(children));
  EXPECT_EQ(sequenceTypeElementProcessor.process(mockXMlElement),
      R"("friend-id": FriendId;
"location": Location;
)");
}