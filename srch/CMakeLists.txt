cmake_minimum_required(VERSION 3.16)
project(corpus LANGUAGES CXX)

# ---- C++ standard ----
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Library target ----
add_library(corpus
    src/corpus.cpp
    src/index.cpp
    src/inverted_index.cpp
)

target_include_directories(corpus
    PUBLIC
        src
)

# ---- Main executable ----
add_executable(corpus_app
    src/main.cpp
)

target_link_libraries(corpus_app
    PRIVATE corpus
)

# ---- GoogleTest ----
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For macOS / Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ---- Tests ----
enable_testing()

add_executable(corpus_tests
    tests/corpus_tests.cpp
)

target_link_libraries(corpus_tests
    PRIVATE
        corpus
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(corpus_tests)
