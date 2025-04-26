impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        let mut result = 1.0;
        if n == 0 {
            return 1.0;
        }
        if n == 1 {
            return x;
        }
        if n == -1 {
            return 1.0 / x;
        }
        let mut x = if n > 0 { x } else { 1.0 / x };
        let mut n: u64 = if n > 0 { n as u64 } else { -n as u64 };
        while n > 0 {
            if n & 0x1 == 1{
                result *= x;
            }
            x *= x;
            n >>= 1;
        }
        return result;
    }
}