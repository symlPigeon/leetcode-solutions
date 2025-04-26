impl Solution {
    pub fn greatest_letter(s: String) -> String {
        let mut char_map = std::collections::HashSet::new();
        for c in s.chars() {
            char_map.insert(c);
        }
        for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ".chars().rev() {
            if char_map.contains(&c) && char_map.contains(&c.to_lowercase().next().unwrap()) {
                return c.to_string();
            }
        }
        return "".to_string();
    }
}
