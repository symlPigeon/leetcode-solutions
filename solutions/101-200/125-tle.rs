impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let mut ptr_head: i32 = 0;
        let mut ptr_tail = s.len() as i32 - 1;
        while ptr_head < ptr_tail {
            while ptr_head < ptr_tail
                && !s.chars().nth(ptr_head as usize).unwrap().is_alphanumeric()
            {
                ptr_head += 1;
            }
            while ptr_head < ptr_tail
                && !s.chars().nth(ptr_tail as usize).unwrap().is_alphanumeric()
            {
                ptr_tail -= 1;
            }
            if !s
                .chars()
                .nth(ptr_head as usize)
                .unwrap()
                .eq_ignore_ascii_case(&s.chars().nth(ptr_tail as usize).unwrap())
            {
                return false;
            }
            ptr_head += 1;
            ptr_tail -= 1;
        }
        true
    }
}
