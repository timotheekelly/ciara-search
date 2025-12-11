use std::collections::HashMap;
use crate::posting::Posting;
use crate::tokenizer::tokenize;

pub struct InvertedIndex {
    pub map: HashMap<String, Vec<Posting>>,
    pub doc_lengths: Vec<usize>,
    pub total_docs: usize,
}

impl InvertedIndex {
    pub fn new() -> Self {
        Self {
            map: HashMap::new(),
            doc_lengths: Vec::new(),
            total_docs: 0,
        }
    }

    pub fn add_document(&mut self, doc_id: usize, text: &str) {
        let tokens = tokenize(text);

        // store document length
        self.doc_lengths.push(tokens.len());
        self.total_docs += 1;

        for token in tokens {
            // get posting list for this token
            let postings = self.map.entry(token).or_insert(vec![]);

            // if last posting is same doc, increment freq
            if let Some(last) = postings.last_mut() {
                if last.doc_id == doc_id {
                    last.freq += 1;
                    continue;
                }
            }

            // otherwise, add a new posting
            postings.push(Posting { doc_id, freq: 1 });
        }
    }
}
