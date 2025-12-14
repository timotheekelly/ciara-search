pub struct BM25Params {
    pub k1: f32,
    pub b: f32,
    pub avgdl: f32,
}

impl BM25Params {
    pub fn default(avgdl: f32) -> Self {
        Self {
            k1: 1.2,
            b: 0.75,
            avgdl,
        }
    }
}

pub fn bm25_score(
    term_freq: f32,
    doc_len: usize,
    doc_freq: usize,
    total_docs: usize,
    params: &BM25Params,
) -> f32 {
    if term_freq == 0.0 {
        return 0.0;
    }

    let k1 = params.k1;
    let b = params.b;
    let avgdl = params.avgdl;

    let idf = ((total_docs as f32 - doc_freq as f32 + 0.5)
        / (doc_freq as f32 + 0.5)).ln();

    let tf_component = 
        (term_freq * (k1 + 1.0)) / 
        (term_freq + k1 * (1.0 - b + b * (doc_len as f32 / avgdl)));

    idf * tf_component
}
