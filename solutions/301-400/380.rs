
struct RandomizedSet {
    hash_map: std::collections::HashMap<i32, usize>,
    values: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        Self {
            hash_map: std::collections::HashMap::new(),
            values: vec![],
        }
    }


    fn insert(&mut self, val: i32) -> bool {
        if let std::collections::hash_map::Entry::Vacant(e) = self.hash_map.entry(val) {
            self.values.push(val);
            e.insert(self.values.len() - 1);
            true
        } else {
            false
        }
    }

    fn remove(&mut self, val: i32) -> bool {
        if self.hash_map.contains_key(&val) {
            self.values[*self.hash_map.get(&val).unwrap()] = self.values[self.values.len() - 1];
            self.hash_map.insert(
                self.values[self.values.len() - 1],
                *self.hash_map.get(&val).unwrap(),
            );
            self.values.pop();
            self.hash_map.remove(&val);
            true
        } else {
            false
        }
    }

    fn get_random(&self) -> i32 {
        use rand::random;
        self.values[random::<u32>() as usize % self.values.len()]
    }
}