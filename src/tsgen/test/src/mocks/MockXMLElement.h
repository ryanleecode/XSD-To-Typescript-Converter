#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <XMLElement.h>

namespace xmlparse {
  class MockXMLElement : public XMLElement {
  public:
    MOCK_CONST_METHOD0(hasValue, bool());

    MOCK_CONST_METHOD0(name, std::optional<std::string>());

    MOCK_CONST_METHOD0(firstChildElement, SharedXMLElement());

    MOCK_CONST_METHOD1(firstChildElement, SharedXMLElement(
        const std::string &name));

    MOCK_CONST_METHOD1(findAttribute, std::shared_ptr<XMLAttribute>(
        const std::string &name));

    MOCK_CONST_METHOD0(nextSiblingElement, SharedXMLElement());

    MOCK_CONST_METHOD1(nextSiblingElement, SharedXMLElement(
        const std::string &name));

    MOCK_CONST_METHOD0(children, std::vector<SharedXMLElement>());

    MOCK_CONST_METHOD1(children, std::vector<SharedXMLElement>(
        const std::string&));
  };
}
