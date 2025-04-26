impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let ss = s.split(' ').collect::<Vec<&str>>();
        if ss.len() != pattern.len() {
            return false;
        }
        let mut map = std::collections::HashMap::new();
        let mut map_r = std::collections::HashMap::new();
        for (cs, ct) in pattern.bytes().zip(ss) {
            println!("{} {}", cs, ct);
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
