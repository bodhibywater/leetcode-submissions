class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracks {
            {')','('}, {']','['}, {'}','{'}
        };

        stack<char> st;

        for (char c : s) {
            if (bracks.count(c)) {
                if (!st.empty() && st.top() == bracks[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
