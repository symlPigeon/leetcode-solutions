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
                _ => stack.push(token.parse::<i32>().unwrap()),
            }
            // println!("{:?}", stack);
        }
        *stack.last().unwrap()
    }

    pub fn calculate(s: String) -> i32 {
        let bs = s.as_bytes();
        let mut helper_stack: Vec<u8> = Vec::new();
        let mut token_stack: Vec<String> = Vec::new();
        let mut last_num_token = false;
        let mut ptr = 0;
        while ptr < bs.len() {
            // skip all null space
            while ptr < bs.len() && bs[ptr] == b' ' {
                ptr += 1;
            }
            if ptr == bs.len() {
                break;
            }
            match bs[ptr] {
                b'+' | b'-' => {
                    if !last_num_token {
                        token_stack.push("0".to_string());
                    }
                    while let Some(token) = helper_stack.pop() {
                        match token {
                            b'+' | b'-' => token_stack.push((token as char).to_string()),
                            _ => {
                                helper_stack.push(token);
                                break;
                            }
                        }
                    }
                    helper_stack.push(bs[ptr]);
                    last_num_token = false;
                    ptr += 1;
                }
                b'(' => {
                    helper_stack.push(bs[ptr]);
                    last_num_token = false;
                    ptr += 1;
                }
                b')' => {
                    while let Some(token) = helper_stack.pop() {
                        if token == b'(' {
                            break;
                        } else {
                            token_stack.push((token as char).to_string());
                        }
                    }
                    last_num_token = true;
                    ptr += 1;
                }
                _ => {
                    let mut current_token = String::new();
                    while ptr < bs.len() && bs[ptr].is_ascii_digit() {
                        current_token.push(bs[ptr] as char);
                        ptr += 1;
                    }
                    token_stack.push(current_token);
                    last_num_token = true;
                }
            }
        }
        while let Some(token) = helper_stack.pop() {
            token_stack.push((token as char).to_string());
        }
        println!("{:?}", token_stack);
        Solution::eval_rpn(token_stack)
    }
}