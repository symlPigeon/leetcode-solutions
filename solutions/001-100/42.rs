impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut cnt = 0;
        let columns = height.iter().max().unwrap();
        for col in 0..*columns {
            let head = height.iter().position(|x| *x > col);
            let tail = height.iter().rposition(|x| *x > col);
            if head.is_none() {
                return cnt;
            }
            let head = head.unwrap();
            let tail = tail.unwrap();
            cnt += (head..tail)
                .map(|idx| if height[idx] <= col { 1 } else { 0 })
                .sum::<i32>();
        }
        cnt
    }
}
