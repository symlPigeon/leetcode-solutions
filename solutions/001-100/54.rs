impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut ptr_x = 0;
        let mut ptr_y = 0;
        // border U, R, B, L
        let mut border = (0_usize, matrix[0].len() - 1, matrix.len() - 1, 0_usize);
        // direction U, R, B, L
        let mut direction = 1_usize;
        for _ in 0..(matrix.len() * matrix[0].len()) {
            ans.push(matrix[ptr_y][ptr_x]);
            // check if we arrive at the border
            match direction {
                0 => {
                    if ptr_y == border.0 {
                        // turn right
                        direction = 1;
                        border.3 += 1;
                    }
                }
                1 => {
                    if ptr_x == border.1 {
                        // turn down
                        direction = 2;
                        border.0 += 1;
                    }
                }
                2 => {
                    if ptr_y == border.2 {
                        // turn left
                        direction = 3;
                        border.1 -= 1;
                    }
                }
                3 => {
                    if ptr_x == border.3 {
                        // turn up
                        direction = 0;
                        border.2 -= 1;
                    }
                }
                _ => unreachable!(),
            }
            match direction {
                0 => {
                    ptr_y -= 1;
                }
                1 => {
                    ptr_x += 1;
                }
                2 => {
                    ptr_y += 1;
                }
                3 => {
                    ptr_x -= 1;
                }
                _ => unreachable!(),
            }
        }
        ans
    }
}