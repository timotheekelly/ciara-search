#pragma once
#include <filesystem>
#include <vector>
#include "corpus/model/document.h"

std::vector<Document> load_corpus(const std::filesystem::path& directory_path);