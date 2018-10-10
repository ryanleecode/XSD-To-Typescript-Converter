#include <gtest/gtest.h>
#include <PascalCaseTextProcessorImp.h>

class PascalCaseTextProcessorImpTest : public ::testing::Test {
protected:
  void SetUp() override {
    pascalCaseTextProcessor = new util::PascalCaseTextProcessorImp();
  }

  void TearDown() override {
    delete pascalCaseTextProcessor;
  }
  util::PascalCaseTextProcessorImp* pascalCaseTextProcessor;
};

TEST_F(PascalCaseTextProcessorImpTest, shouldConvertSnakecase) {
  std::string snakeCaseText = "happy_little_frog";
  pascalCaseTextProcessor->process(snakeCaseText);
  ASSERT_STRCASEEQ(snakeCaseText.c_str(), "HappyLittleFrog");
}

TEST_F(PascalCaseTextProcessorImpTest, shouldConvertDashCase) {
  std::string dashCaseText = "dash-case-text";
  pascalCaseTextProcessor->process(dashCaseText);
  ASSERT_STRCASEEQ(dashCaseText.c_str(), "DashCaseText");
}