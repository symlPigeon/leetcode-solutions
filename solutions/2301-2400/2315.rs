impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        let mut count: i16 = 0;
        let mut sts: bool = true;
        for ch in s.chars() {
            match ch {
                '|' => {
                    if sts {
                        sts = false;
                    } else {
                        sts = true;
                    }
                }
                '*' => {
                    if sts {
                        count += 1;
                    }
                }
                _ => {}
            }
        }
        return count as i32;
    }
}
