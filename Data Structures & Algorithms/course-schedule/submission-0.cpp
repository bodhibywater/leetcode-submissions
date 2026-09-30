class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& pre : prerequisites) {
            preMap[pre[0]].push_back(pre[1]); // so every course maps to a vector of its pres
        }
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(int c) {
        if (visiting.count(c)) {
            return false; // cycle detected
        }
        if (preMap[c].empty()) {
            return true;
        }
        visiting.insert(c);
        for (int pre : preMap[c]) { // this gives us vector of pres
            if (!dfs(pre)) {
                return false;
            }
        }
        visiting.erase(c);
        preMap[c].clear();
        return true;
    }
};
