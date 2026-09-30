class Solution {
public:
    vector<string> res;
    vector<string> digMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(digits, 0, "");
        return res;
    }

private:
    void backtrack(string& digits, int i, string cur) {
        if (cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }
        // digit = 245
        string chars = digMap[digits[i] - '0'];
        for (char c : chars) {
            backtrack(digits, i + 1, cur + c);
        }
    }
};
