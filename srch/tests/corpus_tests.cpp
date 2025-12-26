#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

#include "corpus.h"


std::filesystem::path make_temp_dir() {
    std::string tmpl =
        (std::filesystem::temp_directory_path() / "corpus-XXXXXX").string();

    std::vector<char> buffer(tmpl.begin(), tmpl.end());
    buffer.push_back('\0');

    char* result = mkdtemp(buffer.data());
    if (!result) {
        throw std::runtime_error("mkdtemp failed");
    }

    return std::filesystem::path(result);
}

TEST(CorpusLoader, LoadsOnlyTxtFiles) {
    namespace fs = std::filesystem;

    fs::path temp = make_temp_dir();

    std::ofstream(temp / "a.txt") << "hello";
    std::ofstream(temp / "b.txt") << "world";
    std::ofstream(temp / "ignore.md") << "nope";

    auto docs = load_corpus(temp);

    ASSERT_EQ(docs.size(), 2);

    std::vector<std::string> texts;
    for (const auto& d : docs) {
        texts.push_back(d.text);
    }

    std::sort(texts.begin(), texts.end());

    EXPECT_EQ(texts[0], "hello");
    EXPECT_EQ(texts[1], "world");

    fs::remove_all(temp);
}

TEST(CorpusLoader, EmptyDirectoryReturnsEmpty) {
    namespace fs = std::filesystem;

    fs::path temp = make_temp_dir();

    auto docs = load_corpus(temp);
    EXPECT_TRUE(docs.empty());

    fs::remove_all(temp);
}