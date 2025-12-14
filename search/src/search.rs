use crate::bm25::{bm25_score, BM25Params};
use crate::index::InvertedIndex;

pub fn search(idx: &InvertedIndex, query: &str) -> Vec<(usize, f32)> {
    let Some(postings) = idx.map.get(query) else {
        return vec![];
    };

    let total_docs = idx.total_docs;
    let doc_freq = postings.len();
    let avgdl = (idx.doc_lengths.iter().sum::<usize>() as f32) / total_docs as f32;

    let params = BM25Params::default(avgdl);

    let mut scored = Vec::new();

    for post in postings {
        let doc_id = post.doc_id;
        let term_freq = post.freq;

        let doc_len = idx.doc_lengths[doc_id];

        let score = bm25_score(
            term_freq as f32,
            doc_len,
            doc_freq,
            total_docs,
            &params,
        );

        scored.push((doc_id, score));
    }

    // Sort by score descending
    scored.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());

    scored
}
