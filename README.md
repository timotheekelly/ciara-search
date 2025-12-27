# **CIARA Search Engine**

Corpus Indexing & Advanced Retrieval Architecture (CIARA) is a small, experimental search engine built from scratch in C++.
It’s designed as a learning project around indexing, keyword search, and classic information-retrieval techniques (tokenization, inverted indexes, BM25 ranking, etc.).

The engine currently indexes a local corpus of text files (for example, the HTTP/1.1 and HTTP/2 RFCs) and provides ranked search results using a basic BM25 implementation.

The goal is to keep the system simple and transparent while still behaving like a real search engine.

## Features

* Inverted index stored in memory
* Tokenizer with lowercase + simple splitting
* Document length tracking
* BM25 scoring (k1 = 1.2, b = 0.75)
* Ranked search results returned as `(doc_id, score)`
* Works on any folder of `.txt` files

## Project Structure

```
corpus/           Text documents to index
srch/
  src/
    main.cpp              CLI entry point
    inverted_index.cpp    Inverted index construction and storage
    tokenizer.cpp         Tokenization logic
    search.cpp            BM25 scoring and result ranking
    posting.h             Posting list structures
```

## How It Works

1. All `.txt` files in `./corpus` are read and tokenized.
2. For each term, the engine builds a posting list of `(doc_id, term_frequency)`.
3. Document lengths and the overall average document length are computed.
4. Queries are tokenized and scored against the index using BM25.
5. Results are returned in descending score order.

## Running the Project

Add your text files to the `corpus/` directory, then:

```
// TODO
```

You’ll be prompted (or the code will run predefined queries) and see the ranked results printed to stdout.

## Why Build This?

Mostly to understand how real search engines work under the hood.
BM25, posting lists, and ranking functions are usually hidden behind large libraries or services — implementing them directly is a good way to learn the fundamentals.

## Next Steps (Planned)

* Phrase search (using positional indexes)
* Snippet generation
* HTTP API around the engine (Rust or Java)
* Frontend for interactive search
* Admin dashboard for index metrics
* More advanced tokenization
