impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut map = std::collections::HashMap::new();
        let mut map_r = std::collections::HashMap::new();
        for (cs, ct) in s.bytes().zip(t.bytes()) {
            if let Some(&ct_) = &map.get(&cs) {
                if ct != ct_ {
                    return false;
                }
            } else {
                map.insert(cs, ct);
            }
            if let Some(&cs_) = &map_r.get(&ct) {
                if cs != cs_ {
                    return false;
                }
            } else {
                map_r.insert(ct, cs);
            }
        }
        true
    }
}