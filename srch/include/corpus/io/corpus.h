#pragma once
#include <filesystem>
#include <vector>
#include "document.h"

std::vector<Document> load_corpus(const std::filesystem::path& directory_path);