impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![0; nums.len()];
        ans[0] = 1;
        for idx in 1..nums.len() {
            ans[idx] = ans[idx - 1] * nums[idx - 1];
        }
        let mut mul = 1;
        for idx in (0..nums.len()).rev() {
            ans[idx] *= mul;
            mul *= nums[idx];
        }
        ans
    }
}