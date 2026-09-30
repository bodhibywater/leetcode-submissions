class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backtrack(s, 0, 0, cur);
        return res;
    }

private:
    bool isPali(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    } 

    void backtrack(string& s, int i, int j, vector<string>& cur) {
        if (i >= s.size()) {
            if (i == j) {
                res.push_back(cur);
            }
            return;
        }

        if (isPali(s, j, i)) {
            cur.push_back(s.substr(j, i - j + 1));
            backtrack(s, i + 1, i + 1, cur);
            cur.pop_back();
        }

        backtrack(s, i + 1, j, cur);
}
};
