impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut clear_rows = std::collections::HashSet::new();
        let mut clear_cols = std::collections::HashSet::new();
        for ridx in 0..matrix.len() {
            for cidx in 0..matrix[0].len() {
                if matrix[ridx][cidx] == 0 {
                    clear_rows.insert(ridx);
                    clear_cols.insert(cidx);
                }
            }
        }
        for ridx in clear_rows {
            matrix[ridx].fill(0);
        }
        for cidx in clear_cols {
            for ridx in 0..matrix.len() {
                matrix[ridx][cidx] = 0;
            }
        }
    }
}