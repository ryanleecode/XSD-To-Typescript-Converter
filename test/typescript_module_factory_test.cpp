#include <gtest/gtest.h>
#include "../src/tsgen/typescript_module.h"
#include "../src/xmlparse/incorrect_xml_element_name_exception.h"
#include "../src/xmlparse/missing_xml_attribute_exception.h"

class TypescriptModuleFactoryTest : public ::testing::Test {
protected:
  void SetUp() override {
    this->typeScriptModuleFactory = new tsgen::TypeScriptModule::Factory();
    this->document = new tinyxml2::XMLDocument();
  }

  void TearDown() override {
    delete typeScriptModuleFactory;
    delete document;
  }

  tinyxml2::XMLDocument *document{};
  tsgen::TypeScriptModule::Factory *typeScriptModuleFactory{};
};

TEST_F(TypescriptModuleFactoryTest,
       ShouldFailToCreateIfRootElementDoesNotHaveNameSchema) {
  auto xmlString = R"(<?xml version="1.0"encoding="UTF-8"?><xs:notSchema></xs:notSchema>)";
  document->Parse(xmlString);

  EXPECT_THROW(typeScriptModuleFactory->create(*document->RootElement()),
               xmlparse::IncorrectXMLElementNameException);
}

TEST_F(TypescriptModuleFactoryTest,
       ShouldFailToCreateIfRootElementDoesNotHaveAttributeXmlns) {
  auto xmlString = R"(<?xml version="1.0"encoding="UTF-8"?><xs:schema></xs:schema>)";
  document->Parse(xmlString);

  EXPECT_THROW(typeScriptModuleFactory->create(*document->RootElement()),
               xmlparse::MissingXMLAttributeException);
}

TEST_F(TypescriptModuleFactoryTest,
       ShouldCreateATypescriptModuleWithCorrectNamespace) {
  auto xmlString = R"(<?xml version="1.0"encoding="UTF-8"?><xs:schema xmlns="my-namespace"></xs:schema>)";
  document->Parse(xmlString);

  auto typescriptModule = typeScriptModuleFactory->create(*document->RootElement());

  auto trash = typescriptModule->getModuleName().c_str();
  ASSERT_STRCASEEQ(typescriptModule->getModuleName().c_str(), "my-namespace");
}
