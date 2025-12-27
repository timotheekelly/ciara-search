#include "corpus.h"
#include "index.h"

#include <iostream>

int main() {
    auto docs = load_corpus("../../corpus");
    auto index = build_index(docs);

    std::cout << "Indexed " << docs.size() << " documents\n";
}
