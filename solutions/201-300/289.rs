#[repr(i32)]
enum NextStatus {
    KeepAlive = 3,
    KeepDead = 0,
    Revived = 2,
    Killed = 1,
}

impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        for ridx in 0..board.len() {
            for cidx in 0..board[0].len() {
                let mut sum = -board[ridx][cidx];
                for roff in -1..=1 {
                    for coff in -1..=1 {
                        let y = (ridx as i32 + roff) as usize;
                        let x = (cidx as i32 + coff) as usize;
                        sum += if let Some(row) = board.get(y) {
                            row.get(x).unwrap_or(&0) & 1
                        } else {
                            0
                        };
                    }
                }
                print!("{} ", sum);
                board[ridx][cidx] = match board[ridx][cidx] {
                    0 => {
                        if sum == 3 {
                            NextStatus::Revived
                        } else {
                            NextStatus::KeepDead
                        }
                    }
                    1 => {
                        if sum == 2 || sum == 3 {
                            NextStatus::KeepAlive
                        } else {
                            NextStatus::Killed
                        }
                    }
                    _ => unreachable!(),
                } as i32;
            }
            println!();
        }
        for ridx in 0..board.len() {
            for cidx in 0..board[0].len() {
                board[ridx][cidx] >>= 1;
            }
        }
    }
}