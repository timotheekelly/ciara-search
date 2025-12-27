#pragma once

#include <vector>
#include <cstddef>
#include <unordered_map>
#include <string>
#include "analysis/tokenizer.h"

#include "posting.h"

class InvertedIndex {
public:
    InvertedIndex();

    void add_document(
        std::size_t doc_id, 
        std::string_view text, 
        const corpus::analysis::Tokenizer& tokenizer);

    const std::vector<Posting>& posting(const std::string& term) const;

private: 
    std::unordered_map<std::string, std::vector<Posting>> index;
    std::vector<size_t> doc_lengths;
    std::size_t total_docs = 0;
};