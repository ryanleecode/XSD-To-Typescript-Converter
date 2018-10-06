#include <stdexcept>

namespace util {
  class NotImplementedException : public std::logic_error {
  public:
    NotImplementedException();
  };
}