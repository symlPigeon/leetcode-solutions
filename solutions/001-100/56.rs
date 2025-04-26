impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if intervals.len() == 1 {
            return intervals;
        }
        let mut intervals = intervals.clone();
        intervals.sort_by(|a, b| a[0].partial_cmp(&b[0]).unwrap());
        let mut ans = Vec::new();
        let mut last_tuple = intervals[0].clone();
        for i in 1..intervals.len() {
            let next_tuple = &intervals[i];
            if next_tuple[0] <= last_tuple[1] {
                last_tuple[1] = std::cmp::max(next_tuple[1], last_tuple[1]);
            } else {
                ans.push(last_tuple.clone());
                last_tuple = next_tuple.to_vec();
            }
        }
        ans.push(last_tuple);
        ans
    }
}