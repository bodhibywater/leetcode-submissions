// can obviously be done with a hashset and iteration
// acctually no it cant I misread it
// So I guess we make a hashset and add everything to it
// then we can increment through and check for count in hashset
// once we find it we progress l = r + 1
// two pointer however we also have to conisder not taking the word
// so think like a decision tree 
// 

class Solution {
public:
    vector<int> memo;

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hset(wordDict.begin(), wordDict.end());
        memo.resize(s.size(), -1);
        return dp(s, hset, 0);
    }
private:
    bool dp(string s, unordered_set<string>& hset, int i) {
        if (i == s.size()) {
            // I dont even think we need this but just in case I guess
            // can remove for optimising probs but negligable
            return true;
        }
        if (memo[i] != -1) {
            return memo[i] == 1;
        }

        for (int j = i; j < s.size(); j++) {
            if (hset.find(s.substr(i, j - i + 1)) != hset.end()) {
                if (dp(s, hset, j+1)) {
                    memo[i] = 1;
                    return true;
                }
            }
        }
        memo[i] = 0;
        return false;
    }
};
