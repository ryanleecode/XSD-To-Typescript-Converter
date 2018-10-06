#include <gtest/gtest.h>
#include "../src/tsgen/TypescriptPrimitive.h"
#include "../src/tsgen/SimpleType.h"
#include "xmlparse/mocks/MockXMLElement.h"
#include "xmlparse/mocks/MockXMLAttribute.h"
#include "../src/xmlparse/MissingXMLAttributeException.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::ByMove;

class SimpleTypeTest : public ::testing::Test {
protected:
  void SetUp() override {
  }

  void TearDown() override {
  }
};

TEST_F(SimpleTypeTest,
       ShouldThrowIfNoAttrCalledName) {
  xmlparse::MockXMLElement mockXMLElement;
  EXPECT_CALL(mockXMLElement, findAttribute("name"))
      .Times(1);

  EXPECT_THROW(tsgen::SimpleType{mockXMLElement},
               xmlparse::MissingXMLAttributeException);
}

TEST_F(SimpleTypeTest,
       ShouldGenerateABasicStringTypeFromXsString) {
  xmlparse::MockXMLElement mockXMLElement;
  EXPECT_CALL(mockXMLElement, findAttribute("name"))
      .Times(1)
      .WillOnce([](const std::string &name) {
        auto xmlAttribute = std::make_unique<xmlparse::MockXMLAttribute>();
        EXPECT_CALL(*xmlAttribute, value())
            .Times(1)
            .WillOnce(Return("user-id"));

        return std::move(xmlAttribute);
      });

  EXPECT_CALL(mockXMLElement, firstChildElement("xs:restriction"))
      .Times(1)
      .WillOnce([](const std::string &name) {
        auto restrictionElement = std::make_unique<xmlparse::MockXMLElement>();
        EXPECT_CALL(*restrictionElement, findAttribute("base"))
            .Times(1)
            .WillOnce([](const std::string &name) {
              auto baseAttr = std::make_unique<xmlparse::MockXMLAttribute>();
              EXPECT_CALL(*baseAttr, value())
                  .Times(1)
                  .WillOnce(Return("xs:string"));

              return std::move(baseAttr);
            });

        return std::move(restrictionElement);
      });

  tsgen::SimpleType simpleStringType(mockXMLElement);

  auto expectedString = "type UserId = string;";
  ASSERT_STRCASEEQ(simpleStringType.toTypescriptDefinition().c_str(), expectedString);
}

TEST_F(SimpleTypeTest,
       ShouldGenerateABasicNumberTypeFromXsNumber) {
  xmlparse::MockXMLElement mockXMLElement;
  EXPECT_CALL(mockXMLElement, findAttribute("name"))
      .Times(1)
      .WillOnce([](const std::string &name) {
        auto xmlAttribute = std::make_unique<xmlparse::MockXMLAttribute>();
        EXPECT_CALL(*xmlAttribute, value())
            .Times(1)
            .WillOnce(Return("apple-count"));

        return std::move(xmlAttribute);
      });

  EXPECT_CALL(mockXMLElement, firstChildElement("xs:restriction"))
      .Times(1)
      .WillOnce([](const std::string &name) {
        auto restrictionElement = std::make_unique<xmlparse::MockXMLElement>();

        EXPECT_CALL(*restrictionElement, findAttribute("base"))
            .Times(1)
            .WillOnce([](const std::string &name) {
              auto baseAttribute = std::make_unique<xmlparse::MockXMLAttribute>();
              EXPECT_CALL(*baseAttribute, value())
                  .Times(1)
                  .WillOnce(Return("xs:int"));

              return std::move(baseAttribute);
            });

        return std::move(restrictionElement);
      });


  tsgen::SimpleType simpleType(mockXMLElement);

  auto expectedString = "type AppleCount = number;";
  ASSERT_STRCASEEQ(simpleType.toTypescriptDefinition().c_str(), expectedString);
}