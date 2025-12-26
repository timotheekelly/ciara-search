#include "corpus.h"
#include <filesystem>

int main() {
    std::filesystem::path directory = "../corpus";
    load_corpus(directory);
    return 0;
}
