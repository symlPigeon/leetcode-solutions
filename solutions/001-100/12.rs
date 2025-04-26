impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut numstr = String::new();
        match num / 1000 {
            1 => numstr.push_str("M"),
            2 => numstr.push_str("MM"),
            3 => numstr.push_str("MMM"),
            _ => (),
        }
        match (num % 1000) / 100 {
            1 => numstr.push_str("C"),
            2 => numstr.push_str("CC"),
            3 => numstr.push_str("CCC"),
            4 => numstr.push_str("CD"),
            5 => numstr.push_str("D"),
            6 => numstr.push_str("DC"),
            7 => numstr.push_str("DCC"),
            8 => numstr.push_str("DCCC"),
            9 => numstr.push_str("CM"),
            _ => (),
        }
        match (num % 100) / 10 {
            1 => numstr.push_str("X"),
            2 => numstr.push_str("XX"),
            3 => numstr.push_str("XXX"),
            4 => numstr.push_str("XL"),
            5 => numstr.push_str("L"),
            6 => numstr.push_str("LX"),
            7 => numstr.push_str("LXX"),
            8 => numstr.push_str("LXXX"),
            9 => numstr.push_str("XC"),
            _ => (),
        }
        match num % 10 {
            1 => numstr.push_str("I"),
            2 => numstr.push_str("II"),
            3 => numstr.push_str("III"),
            4 => numstr.push_str("IV"),
            5 => numstr.push_str("V"),
            6 => numstr.push_str("VI"),
            7 => numstr.push_str("VII"),
            8 => numstr.push_str("VIII"),
            9 => numstr.push_str("IX"),
            _ => (),
        }
        numstr
    }
}