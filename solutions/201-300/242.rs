impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut map_s = std::collections::HashMap::new();
        s.chars()
            .map(|ch| {
                map_s.entry(ch).and_modify(|v| *v += 1).or_insert(1);
            })
            .collect::<()>();
        let mut map_t = std::collections::HashMap::new();
        t.chars()
            .map(|ch| {
                map_t.entry(ch).and_modify(|v| *v += 1).or_insert(1);
            })
            .collect::<()>();

        for (k, v) in &map_s {
            if let Some(v_) = map_t.get(&k) {
                if v != v_ {
                    return false;
                }
            } else {
                return false;
            }
        }

        for (k, v) in &map_t {
            if let Some(v_) = map_s.get(&k) {
                if v != v_ {
                    return false;
                }
            } else {
                return false;
            }
        }
        true
    }
}