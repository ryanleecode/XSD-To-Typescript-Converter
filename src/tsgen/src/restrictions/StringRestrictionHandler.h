#pragma once

#include <string>
#include <vector>
#include <memory>
#include <set>

namespace tsgen {
  typedef std::pair<std::string, std::string> RestrictionPair;
  typedef std::set<std::string> RestrictionUnion;

  class StringRestrictionHandler {
  public:
    StringRestrictionHandler(
        std::string &restriction,
        const RestrictionUnion &restrictionUnion);

    void handle(
        const std::string &base,
        const std::vector<RestrictionPair> &restrictionPairs);

  private:
    std::string &restriction_;
    const std::set<std::string> &restrictionUnion_;
  };
}




