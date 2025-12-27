#pragma once

#include <vector>
#include <string>

namespace corpus::analysis {

class Tokenizer {
public:
    virtual ~Tokenizer() = default;

    virtual std::vector<std::string> tokenize(std::string_view text) const = 0;
};

}