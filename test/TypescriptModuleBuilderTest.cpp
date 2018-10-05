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
using::testing::ByMove;

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
            .WillOnce(Return(std::optional("xs:notSchema")));

    EXPECT_THROW(typeScriptModuleFactory->createTypescriptModule(xmlElement),
                 xmlparse::IncorrectXMLElementNameException);
}

TEST_F(TypescriptModuleBuilderTest,
       ShouldFailToCreateIfRootElementDoesNotHaveAttributeXmlns) {
    xmlparse::MockXMLElement xmlElement;

    EXPECT_CALL(xmlElement, name())
            .Times(1)
            .WillOnce(Return(std::optional("xs:schema")));

    EXPECT_CALL(xmlElement, findAttribute(_))
            .Times(1);

    EXPECT_THROW(typeScriptModuleFactory->createTypescriptModule(xmlElement),
                 xmlparse::MissingXMLAttributeException);
}

TEST_F(TypescriptModuleBuilderTest,
       ShouldCreateATypescriptModuleWithCorrectNamespace) {
    xmlparse::MockXMLElement xmlElement;
    EXPECT_CALL(xmlElement, name())
            .Times(1)
            .WillOnce(Return(std::optional("xs:schema")));

    EXPECT_CALL(xmlElement, findAttribute(requiredAttributeName))
            .Times(2)
            .WillOnce([](const std::string& attrName) {
                return std::make_unique<xmlparse::MockXMLAttribute>();
            })
            .WillOnce([](const std::string& attrName) {
                auto xmlAttribute = std::make_unique<xmlparse::MockXMLAttribute>();
                EXPECT_CALL(*xmlAttribute, value())
                        .Times(1)
                        .WillOnce(Return(std::optional("my-namespace")));
                return std::move(xmlAttribute);
            });

    auto typescriptModule = typeScriptModuleFactory->createTypescriptModule(xmlElement);

    ASSERT_STRCASEEQ(typescriptModule->getModuleName().c_str(), "my-namespace");
}
