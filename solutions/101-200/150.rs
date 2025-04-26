impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();
        for token in tokens {
            match token.as_str() {
                "+" => {
                    let a = stack.pop().unwrap();
                    *stack.last_mut().unwrap() += a;
                }
                "-" => {
                    let a = stack.pop().unwrap();
                    *stack.last_mut().unwrap() -= a;
                }
                "*" => {
                    let a = stack.pop().unwrap();
                    *stack.last_mut().unwrap() *= a;
                }
                "/" => {
                    let a = stack.pop().unwrap();
                    *stack.last_mut().unwrap() /= a;
                }
                _ => stack.push(token.parse::<i32>().unwrap()),
            }
            // println!("{:?}", stack);
        }
        *stack.last().unwrap()
    }
}