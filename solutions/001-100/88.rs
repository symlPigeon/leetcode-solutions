impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        // first merge at nums1[m..m+n]
        let mut ptr_1 = 0 as usize;
        let mut ptr_2 = 0 as usize;
        let mut ptr_ans = m as usize;
        while ptr_1 < m as usize && ptr_2 < n as usize {
            if nums1[ptr_1] < nums2[ptr_2] {
                nums1[ptr_ans % (m + n) as usize] = nums1[ptr_1];
                ptr_1 += 1;
            } else {
                nums1[ptr_ans % (m + n) as usize] = nums2[ptr_2];
                ptr_2 += 1;
            }
            ptr_ans += 1;
        }
        if (ptr_1 >= m as usize) {
            while ptr_2 < n as usize {
                nums1[ptr_ans % (m + n) as usize] = nums2[ptr_2];
                ptr_2 += 1;
                ptr_ans += 1;
            }
        }
        if (ptr_2 >= n as usize) {
            while ptr_1 < m as usize {
                nums1[ptr_ans % (m + n) as usize] = nums1[ptr_1];
                ptr_1 += 1;
                ptr_ans += 1;
            }
        }
        // rotate
        nums1.rotate_left(m as usize);
    }
}