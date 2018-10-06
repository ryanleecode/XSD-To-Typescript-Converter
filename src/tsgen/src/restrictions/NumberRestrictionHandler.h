#pragma once

#include "RestrictionHandler.h"

namespace tsgen {
  class NumberRestrictionHandler : public RestrictionHandler {
  public:
    explicit NumberRestrictionHandler(std::string &typeString);

    void handle(
        const std::string &base,
        const RestrictionPairs &restrictionPairs) override;

  private:
    typedef std::set<int> RestrictionUnion;
    RestrictionUnion restrictionUnion_;
  };
}




