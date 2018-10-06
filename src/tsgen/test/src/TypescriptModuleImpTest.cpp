#include <gtest/gtest.h>
#include <memory.h>
#include "../../src/TypescriptModuleImp.h"
#include "mocks/MockSimpleType.h"
#include <TypescriptModuleFactory.h>
#include <tinyxml2.h>
#include <XMLElementAdapter.h>

using ::testing::Return;

typedef std::vector<std::unique_ptr<tsgen::SimpleType>> SimpleTypes;

class TypescriptModuleImpTest : public ::testing::Test {
protected:
  void SetUp() override {
    this->typeScriptModuleFactory = new tsgen::TypescriptModuleFactory();
    this->document = new tinyxml2::XMLDocument();
  }

  void TearDown() override {
    delete typeScriptModuleFactory;
    delete document;
  }

  std::unique_ptr<tsgen::MockSimpleType> createMockSimpleType(
      const std::string &returnValue
  ) {
    auto simpleType = std::make_unique<tsgen::MockSimpleType>();
    EXPECT_CALL(*simpleType, toTypescriptDefinition())
        .Times(1)
        .WillOnce(Return(returnValue));

    return std::move(simpleType);
  }

  tinyxml2::XMLDocument *document{};
  tsgen::TypescriptModuleFactory *typeScriptModuleFactory{};
};

TEST_F(TypescriptModuleImpTest,
       ShouldProperlyGenerateStringType) {
  auto simpleTypes = std::make_unique<SimpleTypes>();
  std::vector<std::string> types = {
      "type UserId = string;",
      "type NumberType = number;"
  };
  for (auto &type : types) {
    simpleTypes->push_back(this->createMockSimpleType(type));
  }

  auto typescriptModule2 = tsgen::TypescriptModuleImp("", std::move(simpleTypes));

  auto expectedDefinition = R"(/* tslint:disable */
export type UserId = string;
export type NumberType = number;
)";
  ASSERT_STRCASEEQ(
      typescriptModule2.generateTypescriptSchema().c_str(), expectedDefinition);
}

TEST_F(TypescriptModuleImpTest,
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
      ->createTypescriptModule(xmlparse::XMLElementAdapter(*document->RootElement()));

  auto expectedDefinition = R"(/* tslint:disable */
export type NumberType = 0 | 1 | 2 | 3;
)";
  ASSERT_STRCASEEQ(typescriptModule->generateTypescriptSchema().c_str(), expectedDefinition);
}
