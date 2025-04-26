impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut is_reachable = vec![false; nums.len()];
        is_reachable[0] = true;
        for idx in 0..nums.len() {
            if is_reachable[idx] {
                let mut step = 1_usize;
                while step <= nums[idx] as usize && idx + step < nums.len() {
                    is_reachable[idx + step] = true;
                    step += 1;
                }
            } else {
                break;
            }
        }
        is_reachable[nums.len() - 1]
    }
}