impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        if intervals.is_empty() {
            return Vec::from([new_interval]);
        }
        let mut ans = Vec::new();
        let mut start_ptr = 0;
        // 解决new_interval之前的区间
        while start_ptr < intervals.len() && intervals[start_ptr][1] < new_interval[0] {
            ans.push(intervals[start_ptr].clone());
            start_ptr += 1;
        }
        // 解决可能和new_interval重叠的区间
        let mut merged_interval = new_interval.clone();
        while start_ptr < intervals.len()
            && (intervals[start_ptr][0] <= merged_interval[1]
                && intervals[start_ptr][1] >= merged_interval[0])
        {
            if merged_interval[0] > intervals[start_ptr][0] {
                merged_interval[0] = intervals[start_ptr][0];
            }
            if merged_interval[1] < intervals[start_ptr][1] {
                merged_interval[1] = intervals[start_ptr][1];
            }
            start_ptr += 1;
        }
        ans.push(merged_interval);
        // 解决之后的区间
        while start_ptr < intervals.len() {
            ans.push(intervals[start_ptr].clone());
            start_ptr += 1;
        }
        ans
    }
}