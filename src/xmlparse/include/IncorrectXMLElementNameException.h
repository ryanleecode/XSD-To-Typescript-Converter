#pragma once

#include <stdexcept>

namespace xmlparse {
  class IncorrectXMLElementNameException : public std::runtime_error {
  public:
    explicit IncorrectXMLElementNameException(
        const std::string &foundElementName,
        const std::string &expectedElementName);

    ~IncorrectXMLElementNameException() override;

    const char *what() const noexcept override;

    std::string getFoundElementName() const;

    std::string getExpectedElementName() const;

  private:
    std::string foundElementName_;
    std::string expectedElementName_;
    char* exceptionMessage_;
  };
}




