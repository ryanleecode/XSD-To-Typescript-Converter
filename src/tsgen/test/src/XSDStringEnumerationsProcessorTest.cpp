#include <gtest/gtest.h>
#include <XSDEnumerationsProcessorImp.h>
#include <XSDStringEnumerationsProcessor.h>
#include "mocks/MockXMLElement.h"
#include "mocks/MockXMLAttribute.h"
#include "mocks/MockXSDElementProcessor.h"
#include "XSDSimpleTypeElementProcessor.h"

using ::testing::Return;
using ::testing::_;

class XSDStringEnumerationsProcessorTest : public ::testing::Test {
protected:
  void SetUp() override {

  }

  void TearDown() override {
  }
};

TEST_F (
    XSDStringEnumerationsProcessorTest, shouldBeTheUnionOfTheVectorsValues) {
tsgen::XSDStringEnumerationsProcessor enumerationsProcessorImp;
std::vector<std::shared_ptr<xmlparse::XMLElement>> enumerations;

auto enumerationWords = { "apple", "peach", "orange"};
auto makeMockXMLEnumeration = [&](const std::string& word) {
  auto mockXMLEnumeration = std::make_shared<xmlparse::MockXMLElement>();
  auto mockXMLAttr = std::make_shared<xmlparse::MockXMLAttribute>();
  EXPECT_CALL(*mockXMLEnumeration, findAttribute("value"))
      .Times(1)
      .WillOnce(Return(mockXMLAttr));

  EXPECT_CALL(*mockXMLAttr, value())
      .Times(1)
      .WillOnce(Return(word));

  return mockXMLEnumeration;
};

for (auto& word : enumerationWords) {
enumerations.push_back(makeMockXMLEnumeration(word));
}

EXPECT_EQ(enumerationsProcessorImp.process(enumerations),
    "\"apple\" | \"peach\" | \"orange\"");
}