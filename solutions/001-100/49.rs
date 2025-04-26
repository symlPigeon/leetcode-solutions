impl Solution {
    fn calc_characters(word: &String) -> [u8; 26] {
        let mut ans = [0u8; 26];
        for ch in word.chars() {
            ans[(ch as u8 - 97) as usize] += 1;
        }
        ans
    }

    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map = std::collections::HashMap::new();
        for word in strs {
            let key = Self::calc_characters(&word);
            let key = key
                .iter()
                .map(|x| x.to_string())
                .collect::<Vec<String>>()
                .join(",");
            let entry = map.entry(key).or_insert(vec![]);
            entry.push(word);
        }
        map.into_iter().map(|(_, v)| v).collect()
    }
}
