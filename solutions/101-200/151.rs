impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut ans = Vec::new();
        let mut ptr_tail: i32 = s.len() as i32 - 1;
        while ptr_tail >= 0 {
            while ptr_tail >= 0 && s.as_bytes()[ptr_tail as usize] == b' ' {
                ptr_tail -= 1;
            }
            if ptr_tail < 0 {
                break;
            }
            let mut ptr_head = ptr_tail;
            while ptr_head >= 0 && s.as_bytes()[ptr_head as usize] != b' ' {
                ptr_head -= 1;
            }
            ans.push(&s[(ptr_head + 1) as usize..(ptr_tail + 1) as usize]);
            ptr_tail = ptr_head;
        }
        ans.join(" ")
    }
}