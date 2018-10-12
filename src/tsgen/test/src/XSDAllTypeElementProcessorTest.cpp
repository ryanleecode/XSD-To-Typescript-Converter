
#include <gtest/gtest.h>
#include <XSDElementProcessorImp.h>
#include <XSDAllTypeElementProcessor.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDAllTypeElementProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {
    subProcessors = new tsgen::SharedXSDElementProcessors();
  }

  void TearDown() override {
    delete subProcessors;
  }
  tsgen::SharedXSDElementProcessors* subProcessors;
};

TEST_F (
    XSDAllElementProcessorTest, shouldProcessAsEmptyStringIfNameIsNotAll) {
  tsgen::XSDAllTypeElementProcessor allElementProcessor(*subProcessors);
  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("notAll"));
  EXPECT_EQ(allElementProcessor.process(mockXMlElement), "");
}

TEST_F (
    XSDAllElementProcessorTest, shouldProcessAllTypeCorrectly) {
  const std::string result = "export type cat = string;";
  auto mockSubprocessor = std::make_shared<tsgen::MockXSDElementProcessor>();
  EXPECT_CALL(*mockSubprocessor, process(_))
    .Times(1)
    .WillOnce(Return(result));
  subProcessors->push_back(mockSubprocessor);

  auto mockXMlElement = std::make_shared<xmlparse::MockXMLElement>();
  EXPECT_CALL(*mockXMlElement, name())
      .Times(1)
      .WillOnce(Return("all"));


  std::vector<tsgen::SharedXMLElement> children = {
      std::make_shared<xmlparse::MockXMLElement>()
  };
  EXPECT_CALL(*mockXMlElement, children())
    .Times(1)
    .WillOnce(Return(children));

  tsgen::XSDAllTypeElementProcessor allElementProcessor(*subProcessors);

  EXPECT_EQ(allElementProcessor.process(mockXMlElement), result);
}