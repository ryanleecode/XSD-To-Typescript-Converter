#pragma once

#include <stdexcept>

namespace xmlparse {
  class MissingXMLAttributeException : public std::runtime_error {
  public:
    explicit MissingXMLAttributeException(
        const std::string &expectedAttributeName
    );

    ~MissingXMLAttributeException() override;

    const char *what() const noexcept override;

    std::string getExpectedAttributeName() const;

  private:
    std::string expectedAttributeName_;
    char* exceptionMessage_;
  };
}



