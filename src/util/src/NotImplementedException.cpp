#include "../include/NotImplementedException.h"

namespace util {
  NotImplementedException::NotImplementedException(): std::logic_error("Method is not implemented") {
  }
}
