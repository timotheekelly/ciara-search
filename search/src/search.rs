use crate::index::InvertedIndex;

pub fn search(idx: &InvertedIndex, term: &str) -> Vec<usize> {
    let term = term.to_lowercase();

    idx.map
        .get(&term)
        .map(|postings| postings.iter().map(|p| p.doc_id).collect())
        .unwrap_or_else(|| vec![])
}
