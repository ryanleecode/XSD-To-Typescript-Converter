#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../src/tsgen/TypescriptModule.h"
#include "../src/xmlparse/IncorrectXMLElementNameException.h"
#include "../src/xmlparse/MissingXMLAttributeException.h"
#include "../src/tsgen/TypescriptModuleFactory.h"
#include "xmlparse/mocks/MockXMLElement.h"
#include "xmlparse/mocks/MockXMLAttribute.h"
#include "../src/xmlparse/XMLAttribute/XMLAttributeAdapter.h"
#include "../src/xmlparse/XMLElement/XMLElementAdapter.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::ByMove;

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
  auto xmlString = R"(
    <?xml version="1.0"encoding="UTF-8"?>
    <xs:notSchema>
    </xs:notSchema>
  )";
  document->Parse(xmlString);

  auto xmlElement = xmlparse::XMLElementAdapter(*document->RootElement());

  EXPECT_THROW(typeScriptModuleFactory->createTypescriptModule(xmlElement);,
               xmlparse::IncorrectXMLElementNameException);
}

TEST_F(TypescriptModuleBuilderTest,
       ShouldFailToCreateIfRootElementDoesNotHaveAttributeXmlns) {
  auto xmlString = R"(
    <?xml version="1.0"encoding="UTF-8"?>
    <xs:schema>
    </xs:schema>
  )";
  document->Parse(xmlString);

  auto xmlElement = xmlparse::XMLElementAdapter(*document->RootElement());

  EXPECT_THROW(typeScriptModuleFactory->createTypescriptModule(xmlElement),
               xmlparse::MissingXMLAttributeException);
}

TEST_F(TypescriptModuleBuilderTest,
       ShouldCreateATypescriptModuleWithCorrectNamespace) {
  auto xmlString = R"(
    <?xml version="1.0"encoding="UTF-8"?>
    <xs:schema xmlns="my-namespace">
    </xs:schema>
  )";
  document->Parse(xmlString);

  auto xmlElement = xmlparse::XMLElementAdapter(*document->RootElement());

  auto typescriptModule = typeScriptModuleFactory->createTypescriptModule(xmlElement);

  ASSERT_STRCASEEQ(typescriptModule->getModuleName().c_str(), "my-namespace");
}
