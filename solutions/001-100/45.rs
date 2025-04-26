impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut steps = vec![2147483647; nums.len()];
        steps[0] = 0;
        for idx in 0..nums.len() - 1 {
            let mut stepped = 1_usize;
            while stepped as i32 <= nums[idx] && stepped + idx < nums.len() {
                if steps[idx] + 1 < steps[stepped + idx] {
                    steps[stepped + idx] = steps[idx] + 1;
                }
                stepped += 1;
            }
        }
        steps[nums.len() - 1]
    }
}