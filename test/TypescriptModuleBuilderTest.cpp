#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../src/tsgen/TypescriptModule.h"
#include "../src/xmlparse/IncorrectXMLElementNameException.h"
#include "../src/xmlparse/MissingXMLAttributeException.h"
#include "../src/tsgen/TypescriptModuleFactory.h"
#include "MockXMLElement.h"
#include "MockXMLAttribute.h"
#include "../src/xmlparse/XMLAttributeImp.h"
#include "../src/xmlparse/XMLElementImp.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

const std::string requiredAttributeName = "xmlns";

class TypescriptModuleBuilderTest : public ::testing::Test {
protected:
  void SetUp() override {
    this->typeScriptModuleFactory = new tsgen::TypeScriptModuleFactory();
    this->document = new tinyxml2::XMLDocument();
  }

  void TearDown() override {
    delete typeScriptModuleFactory;
    delete document;
  }

  tinyxml2::XMLDocument *document{};
  tsgen::TypeScriptModuleFactory *typeScriptModuleFactory{};
};

TEST_F(TypescriptModuleBuilderTest,
       ShouldFailToCreateIfRootElementDoesNotHaveNameSchema) {
  xmlparse::MockXMLElement xmlElement;

  EXPECT_CALL(xmlElement, name())
      .Times(1)
      .WillOnce(Return("xs:notSchema"));

  EXPECT_THROW(typeScriptModuleFactory->createTypescriptModule(xmlElement),
               xmlparse::IncorrectXMLElementNameException);
}

TEST_F(TypescriptModuleBuilderTest,
       ShouldFailToCreateIfRootElementDoesNotHaveAttributeXmlns) {
  xmlparse::MockXMLElement xmlElement;

  EXPECT_CALL(xmlElement, name())
      .Times(1)
      .WillOnce(Return("xs:schema"));

  EXPECT_CALL(xmlElement, findAttribute(_))
      .Times(1)
      .WillOnce(Return(nullptr));

  EXPECT_THROW(typeScriptModuleFactory->createTypescriptModule(xmlElement),
               xmlparse::MissingXMLAttributeException);
}

TEST_F(TypescriptModuleBuilderTest,
       ShouldCreateATypescriptModuleWithCorrectNamespace) {
  xmlparse::MockXMLElement xmlElement;
  EXPECT_CALL(xmlElement, name())
      .Times(1)
      .WillOnce(Return("xs:schema"));

  auto xmlElementPtr = std::make_shared<xmlparse::MockXMLAttribute>();

  EXPECT_CALL(xmlElement, findAttribute(requiredAttributeName))
      .Times(2)
      .WillRepeatedly(Return(xmlElementPtr));

  EXPECT_CALL(*xmlElementPtr, value())
      .Times(1)
      .WillOnce(Return("my-namespace"));

  auto typescriptModule = typeScriptModuleFactory->createTypescriptModule(xmlElement);

  ASSERT_STRCASEEQ(typescriptModule->getModuleName().c_str(), "my-namespace");
}
