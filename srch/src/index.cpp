#include "corpus/index/index.h"

InvertedIndex
build_index(
    const std::vector<Document>& docs,
    const corpus::analysis::Tokenizer& tokenizer
) {
    InvertedIndex index;

    for (const auto& doc : docs) {
        index.add_document(doc.id, doc.text, tokenizer);
    }

    return index;
}
