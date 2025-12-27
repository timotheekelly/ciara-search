#pragma once

#include <vector>

#include "document.h"
#include "inverted_index.h"

InvertedIndex
build_index(const std::vector<Document>& docs);
