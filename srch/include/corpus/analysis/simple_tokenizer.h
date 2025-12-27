#pragma once

#include "corpus/analysis/tokenizer.h"

namespace corpus::analysis {

class SimpleTokenizer : public Tokenizer {

public:
    std::vector<std::string> tokenize(std::string_view text) const override;
};
}