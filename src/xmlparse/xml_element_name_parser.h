#pragma once

#include <string>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/join.hpp>

namespace xmlparse {
  class XMLElementNameToCamelCaseConverter {
  public:
    XMLElementNameToCamelCaseConverter(const std::string &name);

    std::string getCamelCaseName();

  private:
    std::string name_;
  };
}




