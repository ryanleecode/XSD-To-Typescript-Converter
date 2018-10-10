#include <gtest/gtest.h>
#include <NotImplementedException.h>

class NotImplementedExceptionTest : public ::testing::Test {
protected:
  void SetUp() override {
    exception = new util::NotImplementedException();
  }

  void TearDown() override {
    delete exception;
  }
  util::NotImplementedException *exception;
};

TEST_F(NotImplementedExceptionTest, ShouldHaveCorrectMessage) {
  std::string expectedText = "Method is not implemented";

  ASSERT_STRCASEEQ(exception->what(), expectedText.c_str());

}