impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }
        if s.len() as i32 <= num_rows {
            return s;
        }
        let mut ans = String::new();
        if num_rows == 2 {
            (0..s.len() / 2)
                .map(|idx| ans.push(s.chars().nth(idx * 2).unwrap()))
                .collect::<()>();
            if s.len() % 2 == 1 {
                ans.push(s.chars().last().unwrap());
            }
            (0..s.len() / 2)
                .map(|idx| ans.push(s.chars().nth(idx * 2 + 1).unwrap()))
                .collect::<()>();
            return ans;
        }
        let krange = s.len() / (2 * num_rows as usize - 2_usize);
        (0..=krange)
            .map(|idx| {
                if (idx * (2 * num_rows - 2) as usize) < s.len() {
                    ans.push(s.chars().nth(idx * (2 * num_rows - 2) as usize).unwrap());
                }
            })
            .collect::<()>();
        (1..(num_rows - 1))
            .map(|row| {
                let krange = (s.len() as i32 - row) / (2 * num_rows - 2);
                for i in 0..krange {
                    ans.push(
                        s.chars()
                            .nth((i * (2 * num_rows - 2) + row) as usize)
                            .unwrap(),
                    );
                    ans.push(
                        s.chars()
                            .nth(((i + 1) * (2 * num_rows - 2) - row) as usize)
                            .unwrap(),
                    );
                }
                if let Some(ch) = s.chars().nth((krange * (2 * num_rows - 2) + row) as usize) {
                    ans.push(ch);
                }
                if let Some(ch) = s
                    .chars()
                    .nth(((krange + 1) * (2 * num_rows - 2) - row) as usize)
                {
                    ans.push(ch);
                }
            })
            .collect::<()>();
        let krange = (s.len() as i32 - num_rows + 1) / (2 * num_rows - 2);
        (0..=krange)
            .map(|idx| {
                if ((idx * (2 * num_rows - 2) + num_rows - 1) as usize) < s.len() {
                    ans.push(
                        s.chars()
                            .nth((idx * (2 * num_rows - 2) + num_rows - 1) as usize)
                            .unwrap(),
                    );
                }
            })
            .collect::<()>();
        ans
    }
}