impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        if nums.len() <= 1 {
            return false;
        }
        let mut set = std::collections::HashSet::new();
        let k = if k as usize >= nums.len() {
            nums.len() - 1
        } else {
            k as usize
        };
        for idx in 0..=k as usize {
            if set.contains(&nums[idx]) {
                return true;
            }
            set.insert(nums[idx]);
        }
        for idx in 1..(nums.len() - k as usize) {
            set.remove(&nums[idx - 1]);
            if set.contains(&nums[idx + k as usize]) {
                return true;
            }
            set.insert(nums[idx + k as usize]);
        }
        false
    }
}
