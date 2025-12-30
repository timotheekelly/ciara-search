#include "corpus/io/corpus.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstddef>

std::vector<Document> load_corpus(const std::filesystem::path& directory) {
    namespace fs = std::filesystem;

    std::vector<Document> docs;
    std::size_t doc_id = 0;

    if (!fs::exists(directory)) {
        throw std::runtime_error("Corpus directory does not exist");
    }

    for (const auto& entry : fs::directory_iterator(directory)) {
        if (!entry.is_regular_file()) {
            continue;
        }

        const fs::path& path = entry.path();

        if (path.extension() != ".txt") {
            continue;
        }

        std::ifstream file(path);
        if (!file) {
            throw std::runtime_error("Failed to open file: " + path.string());
        }

        std::ostringstream buffer;
        buffer << file.rdbuf();

        docs.emplace_back(
            doc_id++,
            path.filename().string(),
            buffer.str()
        );
    }

    return docs;
}
