use std::collections::HashMap;
use crate::posting::Posting;
use crate::tokenizer::tokenize;

pub struct InvertedIndex {
    pub map: HashMap<String, Vec<Posting>>,
}

impl InvertedIndex {
    pub fn new() -> Self {
        Self { map: HashMap::new() }
    }

    pub fn add_document(&mut self, doc_id: usize, text: &str) {
        let tokens = tokenize(text);

        for token in tokens {
            let postings = self.map.entry(token).or_insert(vec![]);

            if let Some(last) = postings.last_mut() {
                if last.doc_id == doc_id {
                    last.freq += 1;
                    continue;
                }
            }

            postings.push(Posting { doc_id, freq: 1 });
        }
    }
}
