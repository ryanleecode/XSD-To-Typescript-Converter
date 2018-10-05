#include <gtest/gtest.h>
#include "../../src/xmlparse/MissingXMLAttributeException.h"

class MissingXMLAttributeExceptionTest : public ::testing::Test {
protected:
  void SetUp() override {
    exception = new xmlparse::MissingXMLAttributeException(
        expectedXMLAttributeName_);
  }

  void TearDown() override {
    delete exception;
  }

  const std::string expectedXMLAttributeName_ = "xs:attribute";
  xmlparse::MissingXMLAttributeException *exception{};
};

TEST_F (MissingXMLAttributeExceptionTest, ShouldHaveCorrectWhatMsg) {
  std::stringstream expectedText;
  expectedText << "Expected XML element to have attribute: "
               << expectedXMLAttributeName_
               << ".\n";
  ASSERT_STRCASEEQ(exception->what(), expectedText.str().c_str());
}

TEST_F (MissingXMLAttributeExceptionTest,
        ShouldGetExpectedElementNameCorrectly) {
  ASSERT_STRCASEEQ(exception->getExpectedAttributeName().c_str(),
                   expectedXMLAttributeName_.c_str());
}
