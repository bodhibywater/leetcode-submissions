
// this is effectively the same as last question, but we have to push_back our recurses into a res 
// vector if they get to the end

class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
    unordered_set<int> visited;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;

        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& pre : prerequisites) {
            preMap[pre[0]].push_back(pre[1]); // so now all courses map to a vector of pres
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(res, c)) {
                return {};
            }
        }
        return res;
    }
private:
    bool dfs(vector<int>& res, int c) {
        if (visiting.count(c)) {
            return false; // cycle detected
        }
        if (visited.count(c)) {
            return true;
        }
        visiting.insert(c);
        for (int pre : preMap[c]) {
            if (!dfs(res, pre)) {
                return false;
            }
        }
        visiting.erase(c);
        visited.insert(c);
        preMap[c].clear();
        res.push_back(c);
        return true;
    }
};
