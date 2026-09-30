class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> svPair;

        for (int i = 0; i < position.size(); i++) {
            svPair.push_back({position[i], speed[i]});
        }
        sort(svPair.rbegin(), svPair.rend());
        stack<double> st;
        for (const auto& [dist, speed] : svPair) {
            double time = (double)(target - dist) / (double)speed;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
};
