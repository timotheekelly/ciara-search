#pragma once
#include <string>

struct Document {
    size_t id;
    std::string filename;
    std::string text;

    explicit Document(size_t id, std::string filename, std::string text)
        : id(id), 
        filename(std::move(filename)), 
        text(std::move(text)) {}
};