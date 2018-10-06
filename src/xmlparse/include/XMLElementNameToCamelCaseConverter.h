#pragma once

#include <string>

namespace xmlparse {
  class XMLElementNameToCamelCaseConverter {
  public:
    XMLElementNameToCamelCaseConverter(const std::string &name);

    std::string getCamelCaseName();

  private:
    std::string name_;
  };
}




