mod tokenizer;
mod posting;
mod index;
mod search;

use std::fs;
use index::InvertedIndex;

fn load_corpus(dir: &str) -> Vec<(usize, String, String)> {
    let mut docs = Vec::new();

    let paths = fs::read_dir(dir).expect("Failed to read corpus directory");

    for (doc_id, entry) in paths.enumerate() {
        let entry = entry.expect("Failed to read directory entry");
        let path = entry.path();

        if path.extension().and_then(|s| s.to_str()) == Some("txt") {
            let filename = path.file_name().unwrap().to_string_lossy().to_string();
            let text = fs::read_to_string(&path)
                .unwrap_or_else(|_| panic!("Failed to read file: {:?}", path));

            docs.push((doc_id, filename, text));
        }
    }

    docs
}

fn test_search(term: &str, idx: &InvertedIndex, filenames: &Vec<String>) {
    let results = search::search(idx, term);

    println!("\n=== Search: '{}' ===", term);

    if results.is_empty() {
        println!("No documents contain this term.");
        return;
    }

    for doc_id in results {
        if let Some(name) = filenames.get(doc_id) {
            println!("- [{}] {}", doc_id, name);
        } else {
            println!("- [{}] <unknown filename>", doc_id);
        }
    }
}


fn main() {
    println!("CIARA Indexer starting...");

    // Load corpus from ../corpus relative to this project
    let corpus_path = "../corpus";
    let corpus = load_corpus(corpus_path);

    println!("Loaded {} documents.", corpus.len());

    let mut filenames: Vec<String> = Vec::new();

    let mut idx = InvertedIndex::new();

    // Index each document
    for (doc_id, filename, text) in &corpus {
        filenames.push(filename.clone());
        idx.add_document(*doc_id, text);
    }

    // Run a sample search
    let terms = vec!["problematic", "cache", "concurrency"];

    for term in terms {
        test_search(term, &idx, &filenames);
    }

}
