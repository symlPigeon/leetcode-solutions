impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut stock = prices[0];
        let mut profit = 0;

        for idx in 1..prices.len() {
            // 如果价格比前一天高，那就出售。
            // 如果价格比前一天低，就假设今天买了。
            if prices[idx] > stock {
                // 出售
                profit += prices[idx] - stock;
                stock = prices[idx];
            } else {
                stock = prices[idx];
            }
        }
        profit
    }
}