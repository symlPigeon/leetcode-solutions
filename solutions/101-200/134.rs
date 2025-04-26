impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        if gas.iter().sum::<i32>() < cost.iter().sum::<i32>() {
            return -1;
        }

        let mut start_idx = 0;
        loop {
            let mut remainder = 0;
            let mut ptr_idx = start_idx;
            loop {
                remainder += gas[ptr_idx] - cost[ptr_idx];
                ptr_idx += 1;
                ptr_idx %= gas.len();
                if remainder < 0 {
                    break;
                }
                if ptr_idx == start_idx {
                    return start_idx as i32;
                }
            }
            start_idx = ptr_idx;
        }
    }
}