impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut ptr_modify = 0;
        let mut ptr_scan = 0;
        while ptr_scan < nums.len() {
            nums[ptr_modify] = nums[ptr_scan];
            ptr_scan += 1;
            // 如果出现两次
            if ptr_scan < nums.len() && nums[ptr_scan] == nums[ptr_modify] {
                // 保存第二个元素
                ptr_modify += 1;
                nums[ptr_modify] = nums[ptr_scan];
                ptr_scan += 1;
                // 排除其余重复元素
                while ptr_scan < nums.len() && nums[ptr_modify] == nums[ptr_scan] {
                    ptr_scan += 1;
                }
            }
            ptr_modify += 1;
        }
        ptr_modify as i32
    }
}