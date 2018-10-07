#include "XMLNullAttribute.h"

namespace xmlparse {
  std::string XMLNullAttribute::value() const {
    return "";
  }

  bool XMLNullAttribute::hasValue() const {
    return false;
  }
}
