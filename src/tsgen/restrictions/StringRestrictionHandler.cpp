#include "StringRestrictionHandler.h"

namespace tsgen {
  StringRestrictionHandler::StringRestrictionHandler(
      std::string &restriction,
      const RestrictionUnion &restrictionUnion
  ): restriction_(restriction), restrictionUnion_(restrictionUnion) {
  }


  void  StringRestrictionHandler::handle(
      const std::string &base,
      const std::vector<RestrictionPair> &restrictionPairs
  ) {
    if (base == "xs:string") {
      this->restriction_ = "string";
    }
  }
}