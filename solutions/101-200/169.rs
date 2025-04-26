impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut value = nums[0];
        let mut score = 1;
        for idx in 1..nums.len() {
            if value != nums[idx] {
                score -= 1;
            } else {
                score += 1;
            }
            if score < 0 {
                value = nums[idx];
                score = 1;
            }
        }
        value
    }
}