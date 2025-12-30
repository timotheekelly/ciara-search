#include "corpus/analysis/simple_tokenizer.h"

#include <cctype>
#include <string>
#include <vector>


namespace corpus::analysis {

std::vector<std::string>
SimpleTokenizer::tokenize(std::string_view text) const {
    std::vector<std::string> tokens;
    std::string current;

    for (unsigned char c : text) {
        if (std::isalnum(c)) {
            current.push_back(std::tolower(c));
        } else if (!current.empty()) {
            tokens.push_back(std::move(current));
            current.clear();
        }
    }

    if (!current.empty()) {
        tokens.push_back(std::move(current));
    }

    return tokens;
}

} // namespace corpus::analysis
