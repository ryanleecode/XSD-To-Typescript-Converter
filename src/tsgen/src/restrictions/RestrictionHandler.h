#pragma once

#include <string>
#include <set>
#include <vector>
#include <unordered_map>

namespace tsgen {
  typedef std::unordered_multimap<std::string, std::string> RestrictionPairs;

  class RestrictionHandler {
  public:
    explicit RestrictionHandler(std::string &typeString);

    virtual ~RestrictionHandler() = default;

    virtual void handle(
        const std::string &base,
        const RestrictionPairs &restrictionPairs) = 0;

  protected:
    std::string &typeString_;

  };
}