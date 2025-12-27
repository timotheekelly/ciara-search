#include "index.h"

InvertedIndex
build_index(const std::vector<Document>& docs) {
    InvertedIndex index;

    for (const auto& doc : docs) {
        index.add_document(doc.id, doc.text);
    }

    return index;
}
