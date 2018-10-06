#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <tinyxml2.h>
#include <TypescriptModuleFactory.h>
#include <XMLElementAdapter.h>
#include <IncorrectXMLElementNameException.h>
#include <MissingXMLAttributeException.h>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::ByMove;

const std::string requiredAttributeName = "xmlns";

class TypescriptModuleBuilderTest : public ::testing::Test {
protected:
  void SetUp() override {
    this->typeScriptModuleFactory = new tsgen::TypescriptModuleFactory();
    this->document = new tinyxml2::XMLDocument();
  }

  void TearDown() override {
    delete typeScriptModuleFactory;
    delete document;
  }

  tinyxml2::XMLDocument *document{};
  tsgen::TypescriptModuleFactory *typeScriptModuleFactory{};
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
