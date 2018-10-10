
#include <PascalCaseTextProcessorImp.h>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/join.hpp>

void util::PascalCaseTextProcessorImp::process(std::string &text) const {
  boost::trim(text);
  std::vector<std::string> words;
  boost::split(words, text, boost::is_any_of("-,_"));
  for (unsigned int i = 0; i < words.size(); i += 1) {
    words[i][0] = (unsigned char) toupper(words[i][0]);
  }
  text = boost::algorithm::join(words, "");
}
