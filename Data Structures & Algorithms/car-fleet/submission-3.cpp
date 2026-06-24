class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> pairs;

        for (int i = 0; i < position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.begin(), pairs.end());

        stack<double> times;

        for (auto& info : pairs) {
            int pos = info.first;
            int s = info.second;

            double time = (double)(target - pos) / s;

            while (!times.empty() && times.top() <= time) {
                times.pop();
            }

            times.push(time);
        }

        return times.size();

    }
};
