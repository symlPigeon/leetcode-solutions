impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let romans = std::collections::HashMap::from([
            ('I', 1),
            ('V', 5),
            ('X', 10),
            ('L', 50),
            ('C', 100),
            ('D', 500),
            ('M', 1000),
        ]);
        let mut sum = *romans.get(&s.chars().nth(0).unwrap()).unwrap();
        for idx in 1..s.len() {
            let prev = romans.get(&s.chars().nth(idx - 1).unwrap()).unwrap();
            let curr = romans.get(&s.chars().nth(idx).unwrap()).unwrap();
            if prev < curr {
                sum -= 2 * prev;
            }
            sum += curr;
        }
        sum
    }
}