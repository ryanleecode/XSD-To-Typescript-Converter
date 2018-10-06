#include "StringRestrictionHandler.h"

namespace tsgen {
  StringRestrictionHandler::StringRestrictionHandler(
      std::string &restriction
  ) : RestrictionHandler(restriction) {
  }

  void  StringRestrictionHandler::handle(
      const std::string &base,
      const RestrictionPairs &restrictionPairs
  ) {
    if (base == "xs:string") {
      this->typeString_ = "string";
    }
  }
}