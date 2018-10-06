#pragma once

#include <string>
#include <vector>
#include <memory>
#include <set>
#include "RestrictionHandler.h"

namespace tsgen {
  class StringRestrictionHandler : public RestrictionHandler {
  public:
    explicit StringRestrictionHandler(std::string &restriction);

    void handle(
        const std::string &base,
        const RestrictionPairs &restrictionPairs) override;

  private:
    typedef std::set<std::string> RestrictionUnion;
    RestrictionUnion restrictionUnion_;
  };
}




