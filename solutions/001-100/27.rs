impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut ptr_front = 0;
        let mut ptr_end = nums.len() - 1;
        let mut cnt = 0;

        for num in nums.iter() {
            if *num != val {
                cnt += 1;
            }
        }

        while ptr_front < cnt {
            if nums[ptr_front] == val {
                while nums[ptr_end] == val {
                    ptr_end -= 1;
                }
                nums[ptr_front] = nums[ptr_end];
                ptr_end -= 1;
            }
            ptr_front += 1;
        }

        cnt as i32
    }
}