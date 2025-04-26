impl Solution {
    pub fn find_min_arrow_shots(points: Vec<Vec<i32>>) -> i32 {
        if points.len() == 1 {
            return 1;
        }
        let mut intervals = points.clone();
        intervals.sort();
        let mut ans = 1;
        let mut merged_interval = intervals[0].clone();
        for interval in intervals.iter().skip(1) {
            if merged_interval[1] >= interval[0] && merged_interval[0] <= interval[1] {
                merged_interval[0] = i32::max(merged_interval[0], interval[0]);
                merged_interval[1] = i32::min(merged_interval[1], interval[1]);
            } else {
                ans += 1;
                merged_interval = interval.clone();
            }
        }
        ans
    }
}
