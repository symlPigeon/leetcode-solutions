impl Solution {
    fn compare(map_s: &[i32; 128], map_t: &[i32; 128]) -> bool {
        for ch in 'A'..='Z' {
            if map_s[ch as usize] < map_t[ch as usize] {
                return false;
            }
        }
        for ch in 'a'..='z' {
            if map_s[ch as usize] < map_t[ch as usize] {
                return false;
            }
        }
        true
    }

    pub fn min_window(s: String, t: String) -> String {
        if s.len() < t.len() {
            return "".to_string();
        }
        let mut s_map = [0; 128];
        let mut t_map = [0; 128];
        t.chars().map(|ch| t_map[ch as usize] += 1).collect::<()>();
        // s_map[s.chars().nth(0).unwrap() as usize] += 1;
        let mut min_win_sz = usize::MAX;
        let mut best_left = 0;
        let mut sptr = 0;
        for tptr in 0..s.len() {
            let curr = s.as_bytes()[tptr] as usize;
            s_map[curr] += 1;
            if t_map[curr] != 0 {
                while Solution::compare(&s_map, &t_map) && sptr <= tptr {
                    if tptr - sptr + 1 < min_win_sz {
                        min_win_sz = tptr - sptr + 1;
                        best_left = sptr;
                    }
                    s_map[s.as_bytes()[sptr] as usize] -= 1;
                    sptr += 1;
                }
            }
        }
        if min_win_sz > s.len() {
            "".to_string()
        } else {
            s[best_left..best_left + min_win_sz].to_string()
        }
    }
}
