impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut word_cnt = std::collections::HashMap::new();
        for ch in magazine.bytes() {
            word_cnt.entry(ch).and_modify(|v| *v += 1).or_insert(1);
        }
        for ch in ransom_note.bytes() {
            if let Some(value) = word_cnt.get_mut(&ch) {
                if *value == 0 {
                    return false;
                }
                *value -= 1;
            } else {
                return false;
            }
        }
        true
    }
}