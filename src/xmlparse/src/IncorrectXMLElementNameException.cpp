#include <sstream>
#include <cstring>
#include <IncorrectXMLElementNameException.h>

std::string xmlparse::IncorrectXMLElementNameException::getFoundElementName() const {
  return this->foundElementName_;
}

std::string xmlparse::IncorrectXMLElementNameException::getExpectedElementName() const {
  return this->expectedElementName_;
}

const char *xmlparse::IncorrectXMLElementNameException::what() const noexcept {
  return this->exceptionMessage_;
}

xmlparse::IncorrectXMLElementNameException::IncorrectXMLElementNameException(
    const std::string &foundElementName,
    const std::string &expectedElementName) : runtime_error(""),
                                              foundElementName_(foundElementName),
                                              expectedElementName_(expectedElementName) {
  auto exceptionMessage = "Expected the root of the XML element to have the "
                          "name: "
                          + this->expectedElementName_
                          + ".\n"
                          + "But found: "
                          + this->foundElementName_
                          + ".\n";
  this->exceptionMessage_ = new char[exceptionMessage.length() + 1];
  strcpy(this->exceptionMessage_, exceptionMessage.c_str());
}

xmlparse::IncorrectXMLElementNameException::~IncorrectXMLElementNameException() {
  delete this->exceptionMessage_;
}
