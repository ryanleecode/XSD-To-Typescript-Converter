#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <XMLElement.h>

namespace xmlparse {
  class MockXMLElement : public XMLElement {
  public:
    MOCK_CONST_METHOD0(hasValue, bool());

    MOCK_CONST_METHOD0(name, std::optional<std::string>());

    MOCK_CONST_METHOD0(firstChildElement, std::unique_ptr<XMLElement>());

    MOCK_CONST_METHOD1(firstChildElement, std::unique_ptr<XMLElement>(
        const std::string &name));

    MOCK_CONST_METHOD1(findAttribute, std::unique_ptr<XMLAttribute>(
        const std::string &name));

    MOCK_CONST_METHOD0(nextSiblingElement, std::unique_ptr<XMLElement>());

    MOCK_CONST_METHOD1(nextSiblingElement, std::unique_ptr<XMLElement>(
        const std::string &name));
  };
}
