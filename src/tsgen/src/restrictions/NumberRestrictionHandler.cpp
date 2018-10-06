#include "NumberRestrictionHandler.h"
#include <string>
#include <sstream>
#include <iterator>
#include <experimental/iterator>

tsgen::NumberRestrictionHandler::NumberRestrictionHandler(
    std::string &typeString
) : RestrictionHandler(typeString) {
}

void tsgen::NumberRestrictionHandler::handle(
    const std::string &base,
    const RestrictionPairs &restrictionPairs
) {
  if (base != "xs:int" && base != "xs:decimal") {
    return;
  }
  this->typeString_ = "number";

  auto minInclusive = restrictionPairs.find("xs:minInclusive");
  auto maxInclusive = restrictionPairs.find("xs:maxInclusive");

  if (minInclusive != restrictionPairs.end() &&
      maxInclusive != restrictionPairs.end()) {
    for (auto i = stoi(minInclusive->second); i <= stoi(maxInclusive->second); i++) {
      this->restrictionUnion_.insert(i);
    }
  }

  if (this->restrictionUnion_.size() > 1) {
    std::ostringstream typeStream;
    std::copy(
        this->restrictionUnion_.begin(),
        this->restrictionUnion_.end(),
        std::experimental::make_ostream_joiner(typeStream, " | "));
    this->typeString_ = typeStream.str();
  }
}
