impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut citations = citations.clone();
        citations.sort_by(|a, b| b.cmp(a));
        let mut idx = 0;
        let mut hidx = 0;
        while idx < citations.len() && citations[idx] > idx as i32 {
            hidx = idx + 1;
            idx += 1;
        }
        hidx as i32
    }
}