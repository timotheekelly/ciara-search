#include "corpus/io/corpus.h"
#include "corpus/index/index.h"
#include "corpus/analysis/simple_tokenizer.h"

#include <iostream>

// TODO
// update cmake
// add search (BM25)
// add search engine facade

int main() {
    auto docs = load_corpus("../../corpus");
    corpus::analysis::SimpleTokenizer tokenizer;

    auto index = build_index(docs, tokenizer);

    std::cout << "Indexed " << docs.size() << " documents\n";
}
