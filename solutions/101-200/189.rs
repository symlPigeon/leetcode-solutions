impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let k = k % nums.len() as i32;
        nums.rotate_right(k as usize);
    }
}
