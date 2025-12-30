#pragma once

#include <vector>

#include "corpus/model/document.h"
#include "corpus/index/inverted_index.h"
#include "corpus/analysis/tokenizer.h"

InvertedIndex
build_index(
    const std::vector<Document>& docs,
    const corpus::analysis::Tokenizer& tokenizer
);
