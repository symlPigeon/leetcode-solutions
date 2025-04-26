impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut window_len = 0;
        let mut idx = 0;
        let mut max_len = 0;
        let mut char_map = std::collections::HashSet::new();
        while idx + window_len < s.len() {
            let ch = s[idx + window_len..idx + window_len + 1]
                .chars()
                .next()
                .unwrap();
            if char_map.contains(&ch) {
                char_map.remove(&s[idx..idx + 1].chars().next().unwrap());
                idx += 1;
                window_len -= 1;
            } else {
                char_map.insert(ch);
                window_len += 1;
                if window_len > max_len {
                    max_len = window_len;
                }
            }
        }
        return max_len as i32;
    }
}