#include "corpus/analysis/simple_tokenizer.h"

#include <cctype>

namespace corpus::analysis{
    
std::vector<std::string> SimpleTokenizer::tokenize (std::string_view text) const {
    std::vector<std::string> tokens;
    std::string current;

    for (char c : text) {
        if(std::isalnum(static_cast<unsigned char>(c))) {
            current.push_back(std::tolower(static_cast<unsigned char>(c)));
        } else if (!current.empty()) {
            tokens.push_back(current);
            current.clear();
        }
    }

    if(!current.empty()) {
        tokens.push_back(current);
    }

    return tokens;
}

}