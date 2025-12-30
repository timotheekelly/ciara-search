cmake_minimum_required(VERSION 3.16)
project(ciara LANGUAGES CXX)

# ---- C++ standard ----
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Core library (CIARA engine) ----
add_library(ciara_core
    src/corpus.cpp
    src/index.cpp
    src/inverted_index.cpp
    src/analysis/simple_tokenizer.cpp
)

target_include_directories(ciara_core
    PUBLIC
        include
)

# ---- Main executable ----
add_executable(ciara_app
    app/main.cpp
)

target_link_libraries(ciara_app
    PRIVATE
        ciara_core
)

# ---- GoogleTest ----
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ---- Tests ----
enable_testing()

add_executable(ciara_tests
    tests/corpus_tests.cpp
)

target_link_libraries(ciara_tests
    PRIVATE
        ciara_core
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ciara_tests)
