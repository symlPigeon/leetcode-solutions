impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut ptr_modify = 0;
        let mut ptr_scan = 0;
        while ptr_scan < nums.len() {
            nums[ptr_modify] = nums[ptr_scan];
            ptr_scan += 1;
            while ptr_scan < nums.len() && nums[ptr_scan] == nums[ptr_scan - 1] {
                ptr_scan += 1;
            }
            ptr_modify += 1;
        }
        ptr_modify as i32
    }
}