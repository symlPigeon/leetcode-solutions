impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut cnt = [0; 9];
        // verify each line is ok
        for row in &board {
            let row_ptr = row.as_ptr();
            for i in 0..9 {
                unsafe {
                    let c = *row_ptr.add(i) as u8;
                    if c != b'.' {
                        if *cnt.get_unchecked((c - b'1') as usize) != 0 {
                            println!("row check failed!");
                            return false;
                        }
                        *cnt.get_unchecked_mut((c - b'1') as usize) = 1;
                    }
                }
            }
            cnt.fill(0);
        }
        // verify each column is ok
        for col in 0..9 {
            for row_idx in 0..9 {
                unsafe {
                    let c = *board.get_unchecked(row_idx).get_unchecked(col) as u8;
                    if c != b'.' {
                        if *cnt.get_unchecked((c - b'1') as usize) != 0 {
                            println!("column check failed!");
                            return false;
                        }
                        *cnt.get_unchecked_mut((c - b'1') as usize) = 1;
                    }
                }
            }
            cnt.fill(0);
        }
        // verify each block is ok
        for block_col in 0..3 {
            for block_row in 0..3 {
                unsafe {
                    for element_id in 0..9 {
                        let c = *board
                            .get_unchecked(block_col * 3 + element_id % 3)
                            .get_unchecked(block_row * 3 + element_id / 3)
                            as u8;
                        if c != b'.' {
                            if *cnt.get_unchecked((c - b'1') as usize) != 0 {
                                println!("block check failed!");
                                return false;
                            }
                            *cnt.get_unchecked_mut((c - b'1') as usize) = 1;
                        }
                    }
                    cnt.fill(0);
                }
            }
        }
        true
    }
}
