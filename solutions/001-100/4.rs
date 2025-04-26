impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut merged_nums = Vec::new();
        let mut idx1 = 0;
        let mut idx2 = 0;
        for _ in 0..nums1.len()+nums2.len(){
            if idx1 >= nums1.len(){
                merged_nums.push(nums2[idx2]);
                idx2 += 1;
            }else if idx2 >= nums2.len(){
                merged_nums.push(nums1[idx1]);
                idx1 += 1;
            }else{
                if nums1[idx1] < nums2[idx2]{
                    merged_nums.push(nums1[idx1]);
                    idx1 += 1;
                }else{
                    merged_nums.push(nums2[idx2]);
                    idx2 += 1;
                }
            }
        }
        if (idx1 + idx2) % 2 == 1 {
            return merged_nums[(idx1 + idx2) / 2] as f64;
        } else if idx1 + idx2 == 0 {
            return 0.0;
        }
        return (merged_nums[(idx1 + idx2) / 2 - 1] + merged_nums[(idx1 + idx2) / 2]) as f64 / 2.0;
    }
}