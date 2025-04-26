impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut ptr_tail: i32 = s.len() as i32 - 1;
        while ptr_tail >= 0 && s.chars().nth(ptr_tail as usize).unwrap() == ' ' {
            ptr_tail -= 1;
        }
        let mut ptr_head = ptr_tail;
        while ptr_head >= 0 && s.chars().nth(ptr_head as usize).unwrap() != ' ' {
            ptr_head -= 1;
        }
        ptr_tail - ptr_head
    }
}