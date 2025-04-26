impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        // filp the matrix by the diagonal
        for i in 0..matrix.len() {
            for j in i..matrix.len() {
                let temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // flip the matrix by the vertical axis
        let width = matrix.len();
        for i in 0..matrix.len() {
            for j in 0..matrix.len() / 2 {
                let temp = matrix[i][j];
                matrix[i][j] = matrix[i][width - 1 - j];
                matrix[i][width - 1 - j] = temp;
            }
        }
    }
}