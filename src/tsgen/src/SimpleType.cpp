#include <NotImplementedException.h>
#include "SimpleType.h"

namespace tsgen {
  std::string SimpleType::toTypescriptDefinition() const {
    throw util::NotImplementedException();
  }
}
