class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        array<int, 26> counts{};

        for (size_t i = 0; i < s.size(); ++i) {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }

        return all_of(counts.begin(), counts.end(),
                [](int count) { return count == 0; });
    }
};
