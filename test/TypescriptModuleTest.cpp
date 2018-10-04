#include <gtest/gtest.h>
#include <tinyxml2.h>
#include "../src/tsgen/TypescriptModule.h"
#include "../src/xmlparse/IncorrectXMLElementNameException.h"
#include "../src/xmlparse/MissingXMLAttributeException.h"
#include "../src/tsgen/TypescriptModuleFactory.h"
#include "MockXMLElement.h"
#include "MockXMLAttribute.h"
#include "../src/xmlparse/XMLAttributeImp.h"
#include "../src/xmlparse/XMLElementImp.h"

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
    ShouldProperlyGenerateStringType) {
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
    ->createTypescriptModule(xmlparse::XMLElementImp(*document->RootElement()));

auto expectedDefinition = R"(/* tslint:disable */
export type UserId = string;
export type NumberType = number;
)";
ASSERT_STRCASEEQ(
    typescriptModule->generateTypescriptSchema().c_str(), expectedDefinition);
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
    ->createTypescriptModule(xmlparse::XMLElementImp(*document->RootElement()));

auto expectedDefinition = R"(/* tslint:disable */
export type NumberType = 0 | 1 | 2 | 3;
)";
ASSERT_STRCASEEQ(typescriptModule->generateTypescriptSchema().c_str(), expectedDefinition);
}