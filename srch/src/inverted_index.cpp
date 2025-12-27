#include "inverted_index.h"

#include <sstream>

namespace {
    std::vector<std::string> tokenize(const std::string& text) {
        std::vector<std::string> tokens;
        std::istringstream iss(text);
        std::string token;

        while (iss >> token) {
            tokens.push_back(token);
        }

        return tokens;
    }
}

InvertedIndex::InvertedIndex() = default;

void InvertedIndex::add_document(std::size_t doc_id,
                                 const std::string& text) {
    auto tokens = tokenize(text);

    doc_lengths.push_back(tokens.size());
    ++total_docs;

    for (const auto& token : tokens) {
        auto& postings = index[token];

        if (!postings.empty() && postings.back().doc_id == doc_id) {
            ++postings.back().term_freq;
        } else {
            postings.push_back(Posting{doc_id, 1});
        }
    }
}


const std::vector<Posting>& InvertedIndex::posting(const std::string& term) const {
    static const std::vector<Posting> empty;
    auto it = index.find(term);

    return it == index.end() ? empty : it->second;
}