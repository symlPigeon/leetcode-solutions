impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut carrier = 1;
        let mut ans = Vec::new();
        for digit in digits.iter().rev() {
            ans.push((digit + carrier) % 10);
            if digit + carrier == 10 {
                carrier = 1;
            } else {
                carrier = 0;
            }
        }
        if carrier == 1 {
            ans.push(carrier);
        }
        ans.reverse();
        ans
    }
}
