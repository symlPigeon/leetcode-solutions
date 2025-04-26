impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut ans: Vec<String> = Vec::new();
        for node in path.split("/") {
            // println!("{}", node);
            match node {
                "."  | "" => {}
                ".." => {
                    ans.pop();
                }
                _ => {
                    ans.push(node.to_owned());
                }
            }
        }
        format!("/{}", ans.join("/"))
    }
}