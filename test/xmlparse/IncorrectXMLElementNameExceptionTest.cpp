#include <gtest/gtest.h>
#include "../../src/xmlparse/IncorrectXMLElementNameException.h"

class IncorrectXMLElementNameExceptionTest : public ::testing::Test {
protected:
  void SetUp() override {
    exception = new xmlparse::IncorrectXMLElementNameException(
        foundElementName_,
        expectedElementName_);
  }

  void TearDown() override {
    delete exception;
  }

  const std::string foundElementName_ = "xs:found";
  const std::string expectedElementName_ = "xs:expected";
  xmlparse::IncorrectXMLElementNameException *exception{};
};

TEST_F (IncorrectXMLElementNameExceptionTest, ShouldHaveCorrectWhatMsg) {
  std::stringstream expectedText;
  expectedText << "Expected the root of the XML element to have the name: "
               << expectedElementName_
               << ".\n"
               << "But found: "
               << foundElementName_
               << ".\n";
  ASSERT_STRCASEEQ(exception->what(), expectedText.str().c_str());
}

TEST_F (IncorrectXMLElementNameExceptionTest,
        ShouldGetExpectedElementNameCorrectly) {
  ASSERT_STRCASEEQ(exception->getExpectedElementName().c_str(),
                   expectedElementName_.c_str());
}

TEST_F (IncorrectXMLElementNameExceptionTest,
        ShouldGetFoundElementNameCorrectly) {
  ASSERT_STRCASEEQ(exception->getFoundElementName().c_str(),
                   foundElementName_.c_str());
}
