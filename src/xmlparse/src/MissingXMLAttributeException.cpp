#include <cstring>
#include <MissingXMLAttributeException.h>

namespace xmlparse {
  MissingXMLAttributeException::MissingXMLAttributeException(
      const std::string &expectedAttributeName) : runtime_error(
      ""), expectedAttributeName_(expectedAttributeName) {

    auto exceptionMessage = "Expected XML element to have attribute: "
                            + expectedAttributeName
                            + ".\n";
    this->exceptionMessage_ = new char[exceptionMessage.length() + 1];
    strcpy(this->exceptionMessage_, exceptionMessage.c_str());
  }

  std::string MissingXMLAttributeException::getExpectedAttributeName() const {
    return this->expectedAttributeName_;
  }

  const char *MissingXMLAttributeException::what() const noexcept {
    return this->exceptionMessage_;
  }

  MissingXMLAttributeException::~MissingXMLAttributeException() {
    delete this->exceptionMessage_;
  }
}

