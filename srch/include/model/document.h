#pragma once
#include <string>
#include <cstddef>

struct Document {
    std::size_t id;
    std::string filename;
    std::string text;

    explicit Document(size_t id, std::string filename, std::string text)
        : id(id), 
        filename(std::move(filename)), 
        text(std::move(text)) {}
};