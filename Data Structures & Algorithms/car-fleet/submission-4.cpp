class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> pairs;

        for (int i = 0; i < position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.begin(), pairs.end());

        stack<double> times;

        for (int j = 0; j < pairs.size(); j++) {
            
            double time = (double) (target - pairs[j].first) / pairs[j].second;

            while (!times.empty() && times.top() <= time) {
                times.pop();
            }

            times.push(time);

        }

        return times.size();

    }
};
