class StockSpanner {
public:
    StockSpanner() {
        day = 0;
        prices.push({0, 0});
    }
    
    int next(int price) {
        day += 1;
        
        while (!prices.empty() && prices.top().first <= price) {
            prices.pop();
        }

        int newDay = prices.empty() ? 0 : prices.top().second;

        prices.push({price, day});

        return day - newDay;

    }

private:
    int day;
    stack<pair<int, int>> prices;

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */