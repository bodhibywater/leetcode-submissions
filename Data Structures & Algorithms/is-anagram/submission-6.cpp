class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.length()) return false;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }

        return sMap == tMap;
    }
};
