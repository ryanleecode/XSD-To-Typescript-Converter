#include <gtest/gtest.h>
#include "../src/tsgen/typescript_module.h"
#include "../src/xmlparse/incorrect_xml_element_name_exception.h"
#include "../src/xmlparse/missing_xml_attribute_exception.h"
#include "../src/tsgen/typescript_module_factory.h"

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
  auto xmlString = R"(<?xml version="1.0"encoding="UTF-8"?><xs:notSchema></xs:notSchema>)";
  document->Parse(xmlString);

  EXPECT_THROW(typeScriptModuleFactory->createTypescriptModule(*document->RootElement()),
               xmlparse::IncorrectXMLElementNameException);
}

TEST_F(TypescriptModuleBuilderTest,
       ShouldFailToCreateIfRootElementDoesNotHaveAttributeXmlns) {
  auto xmlString = R"(<?xml version="1.0"encoding="UTF-8"?><xs:schema></xs:schema>)";
  document->Parse(xmlString);

  EXPECT_THROW(typeScriptModuleFactory->createTypescriptModule(*document->RootElement()),
               xmlparse::MissingXMLAttributeException);
}

TEST_F(TypescriptModuleBuilderTest,
       ShouldCreateATypescriptModuleWithCorrectNamespace) {
  auto xmlString = R"(
    <?xml version="1.0"encoding="UTF-8"?>
    <xs:schema xmlns="my-namespace" />
  )";
  document->Parse(xmlString);

  auto typescriptModule = typeScriptModuleFactory->createTypescriptModule(*document->RootElement());

  ASSERT_STRCASEEQ(typescriptModule->getModuleName().c_str(), "my-namespace");
}

class TypescriptModuleTest : public ::testing::Test {
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

TEST_F(TypescriptModuleTest,
       ShouldProperlyGenerateSimpleTypes) {
  auto xmlString = R"(
    <?xml version="1.0"encoding="UTF-8"?>
    <xs:schema xmlns="simple-types">
      <xs:simpleType name="user-id">
        <xs:restriction base="xs:string">
          <xs:length value="8" />
        </xs:restriction>
      </xs:simpleType>
      <xs:simpleType name="number-type">
        <xs:restriction base="xs:int">
        </xs:restriction>
      </xs:simpleType>
    </xs:schema>
  )";
  document->Parse(xmlString);

  auto typescriptModule = typeScriptModuleFactory
      ->createTypescriptModule(*document->RootElement());

  auto expectedDefiniton = R"(/* tslint:disable */
export type NumberType = number;
export type UserId = string;
)";
  ASSERT_STRCASEEQ(typescriptModule->generateTypescriptSchema().c_str(), expectedDefiniton);
}

TEST_F(TypescriptModuleTest,
       ShouldProperlyGenerateEnumerationNumberTypes) {
  auto xmlString = R"(
    <?xml version="1.0"encoding="UTF-8"?>
    <xs:schema xmlns="simple-types">
      <xs:simpleType name="number-type">
        <xs:restriction base="xs:int">
          <xs:enumeration value="0"/>
          <xs:enumeration value="1"/>
          <xs:enumeration value="2"/>
          <xs:enumeration value="3"/>
        </xs:restriction>
      </xs:simpleType>
    </xs:schema>
  )";
  document->Parse(xmlString);

  auto typescriptModule = typeScriptModuleFactory
      ->createTypescriptModule(*document->RootElement());

  auto expectedDefinition = R"(/* tslint:disable */
export type NumberType = 0 | 1 | 2 | 3;
)";
  ASSERT_STRCASEEQ(typescriptModule->generateTypescriptSchema().c_str(), expectedDefinition);
}
