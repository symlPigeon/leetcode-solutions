impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.is_empty() {
            return 0;
        }
        // profits[i]表示第i天出售的时候能够得到的最大利润
        let mut profits = 0;
        // profits[i + 1] =
        //   profits[i]  若是第i+1天出售的利润小于之前
        //   price[i + 1] - low_price 否则
        // 需要维护一个最低价
        let mut lowest_price = prices[0];
        for price in prices.iter().skip(1) {
            if *price < lowest_price {
                // 当然要是i+1天的价格是最低价，那就肯定不考虑这一天出售了
                lowest_price = *price;
            }
            let profit = price - lowest_price;
            profits = if profit > profits { profit } else { profits };
        }
        profits
    }
}