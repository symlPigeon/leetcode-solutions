impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let mut ans = vec![0; ratings.len()];
        for idx in 1..ratings.len() {
            if ratings[idx - 1] < ratings[idx] {
                ans[idx] = ans[idx - 1] + 1;
                continue;
            }
            if ratings[idx - 1] > ratings[idx] {
                if ans[idx - 1] <= ans[idx] {
                    ans[idx - 1] += 1;
                }
                let mut prev_child = idx as i32 - 2;
                while prev_child >= 0
                    && ratings[prev_child as usize] > ratings[prev_child as usize + 1]
                    && ans[prev_child as usize] <= ratings[prev_child as usize + 1]
                {
                    ans[prev_child as usize] += 1;
                    prev_child -= 1;
                }
            }
        }
        for idx in 1..ratings.len() - 1 {
            while ans[idx] > ans[idx - 1] + 1 && ans[idx] > ans[idx + 1] + 1 {
                ans[idx] -= 1;
            }
        }
        ans.iter().sum::<i32>() + ratings.len() as i32
    }
}
