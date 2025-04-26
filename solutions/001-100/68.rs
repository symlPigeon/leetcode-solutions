impl Solution {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let mut ans = Vec::new();
        let mut current_words = Vec::new();
        let mut current_word_length = 0;
        let mut idx = 0;

        while idx < words.len() {
            if current_word_length + words[idx].len() + current_words.len() <= max_width as usize {
                // 当前行放得下
                current_words.push(&words[idx]);
                current_word_length += words[idx].len();
                idx += 1;
            } else {
                // 已经放不下了，开始分配一下
                let remainder = max_width - current_word_length as i32;
                let mut line = String::from(current_words[0]);
                if current_words.len() == 1 {
                    line.push_str(&" ".repeat(remainder as usize));
                } else {
                    let spaces = remainder / (current_words.len() as i32 - 1);
                    let addition_space = remainder % (current_words.len() as i32 - 1);
                    println!("{}, {}", spaces, addition_space);
                    for (idx, word) in current_words.iter().enumerate().skip(1) {
                        if (idx as i32 - 1) < addition_space {
                            line.push_str(&" ".repeat(spaces as usize + 1));
                            line.push_str(word);
                        } else {
                            line.push_str(&" ".repeat(spaces as usize));
                            line.push_str(word);
                        }
                    }
                }
                ans.push(line);
                current_words.clear();
                current_word_length = 0;
            }
        }
        if !current_words.is_empty() {
            let mut line = String::from(current_words[0]);
            for word in current_words.iter().skip(1) {
                line.push(' ');
                line.push_str(word);
            }
            line.push_str(&" ".repeat(max_width as usize - line.len()));
            ans.push(line);
        }

        ans
    }
}