#include <gtest/gtest.h>
#include <XSDSequenceTypeElementProcessor.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"
#include "mocks/MockPascalCaseTextProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDSequenceTypeElementProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {
    pascalCaseTextProcessor = new util::MockPascalCaseTextProcessor();
    sequenceTypeElementProcessor = new tsgen::XSDSequenceTypeElementProcessor(
        *pascalCaseTextProcessor);
  }

  void TearDown() override {
    delete sequenceTypeElementProcessor;
    delete pascalCaseTextProcessor;
  }

  tsgen::SharedXSDElementProcessors *preprocessors;
  tsgen::XSDSequenceTypeElementProcessor *sequenceTypeElementProcessor;
  util::MockPascalCaseTextProcessor *pascalCaseTextProcessor;
};

TEST_F (
    XSDSequenceTypeElementProcessorTest, shouldReturnEmptyStringIfNotASequenceType) {
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("someType"));
  EXPECT_EQ(sequenceTypeElementProcessor->process(mockXMlElement), "");
}

TEST_F (
    XSDSequenceTypeElementProcessorTest, shouldFilterOutChildrenThatAreNotElementTypes) {
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("sequence"));

  EXPECT_CALL(*mockXMlElement, children("element"));
  sequenceTypeElementProcessor->process(mockXMlElement);
}

TEST_F (
    XSDSequenceTypeElementProcessorTest, shouldParseChildrenAsProperKeyValuePairs) {
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("sequence"));

  std::string friendId = "friend-id";
  std::string location = "location";
  std::map<std::string, std::string> keyValuePairs = {
      {friendId, friendId},
      {location, location}
  };

  EXPECT_CALL(*pascalCaseTextProcessor, process(friendId))
      .WillOnce(testing::Invoke([](std::string &word) -> void {
        word = "FriendId";
      }));
  EXPECT_CALL(*pascalCaseTextProcessor, process(location))
      .WillOnce(testing::Invoke([](std::string &word) -> void {
        word = "Location";
      }));

  std::vector<tsgen::SharedXMLElement> children;
  for (const auto &pair: keyValuePairs) {
    auto element = std::make_shared<xmlparse::MockXMLElement>();
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

  EXPECT_CALL(*mockXMlElement, children("element"))
      .WillOnce(Return(children));
  EXPECT_EQ(sequenceTypeElementProcessor->process(mockXMlElement),
            "\t\"friend-id\" : FriendId;\n\t\"location\" : Location;\n");
}

TEST_F (
    XSDSequenceTypeElementProcessorTest, shouldReturnPrimitiveTypesOnProcessingSimpleTypes) {
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("sequence"));

  typedef std::pair<std::string, std::string> StringPair;
  std::vector<StringPair> keyValuePairs = {
      {"some-string",   "string"},
      {"some-decimal",  "decimal"},
      {"some-integer",  "int"},
      {"some-datetime", "dateTime"}
  };

  std::vector<tsgen::SharedXMLElement> children;
  for (const auto &pair: keyValuePairs) {
    auto element = std::make_shared<xmlparse::MockXMLElement>();
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

  EXPECT_CALL(*mockXMlElement, children("element"))
      .WillOnce(Return(children));
  auto result = sequenceTypeElementProcessor->process(mockXMlElement);
  EXPECT_EQ(result,
            "\t\"some-string\" : string;\n\t\"some-decimal\" : number;"
            "\n\t\"some-integer\" : number;\n\t\"some-datetime\" : string;\n");
}