#include <gtest/gtest.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "XSDToTypescriptParseTree.h"
#include "mocks/MockXSDElementProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDToTypescriptParseTreeTest : public ::testing::Test {
protected:
  void SetUp() override {

  }

  void TearDown() override {
  }
};

TEST_F (XSDToTypescriptParseTreeTest, shouldReturnTsLintDisableCommentWhenXSDSchemaIsEmpty) {
  tsgen::SharedXSDElementProcessors subProcessors;
  tsgen::XSDToTypescriptParseTree parseTree(subProcessors);
  tsgen::SharedXMLElement mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  EXPECT_EQ(parseTree.process(mockXMlElement),
            "/* tslint:disable */\n");
}

TEST_F (XSDToTypescriptParseTreeTest, shouldHaveTheResultsOfAllSubprocessors) {
  tsgen::SharedXSDElementProcessors subProcessors;
  auto subProcessor = std::make_shared<tsgen::MockXSDElementProcessor>();
  EXPECT_CALL(*subProcessor, process(_))
      .Times(2)
      .WillOnce(Return("export type Fish = string;\n"))
      .WillOnce(Return("export type Count = number;\n"));
  subProcessors.push_back(subProcessor);

  tsgen::XSDToTypescriptParseTree parseTree(subProcessors);
  auto expectedResult = R"(/* tslint:disable */
export type Fish = string;
export type Count = number;
)";

  auto xmlElement = std::make_shared<xmlparse::MockXMLElement>();

  std::vector<tsgen::SharedXMLElement> mockChildren = {
      std::make_shared<xmlparse::MockXMLElement>(),
      std::make_shared<xmlparse::MockXMLElement>()
  };
  EXPECT_CALL(*xmlElement, children())
      .Times(1)
      .WillOnce(Return(mockChildren));
  EXPECT_EQ(parseTree.process(xmlElement), expectedResult);
}