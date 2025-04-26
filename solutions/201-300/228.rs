impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        if nums.len() == 0 {
            return Vec::new();
        }
        if nums.len() == 1 {
            return Vec::from([format!("{}", nums[0])]);
        }
        let mut start = 0;
        let mut end = 0;
        let mut ans = Vec::new();
        while end < nums.len() - 1 {
            /*println!(
                "nums[{}]={} nums[{}]={}",
                start, nums[start], end, nums[end]
            );*/
            end += 1;
            if nums[end] - nums[end - 1] != 1 {
                // 不连续
                if start == end - 1 {
                    ans.push(format!("{}", nums[start]));
                } else {
                    ans.push(format!("{}->{}", nums[start], nums[end - 1]));
                }
                start = end;
            }
        }
        if start == end {
            ans.push(format!("{}", nums[start]));
        } else {
            ans.push(format!("{}->{}", nums[start], nums[end]));
        }
        ans
    }
}
