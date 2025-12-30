#pragma once

#include <cstddef>

struct Posting {
    std::size_t doc_id;
    std::size_t term_freq;
};
