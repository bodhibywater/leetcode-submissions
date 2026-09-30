// we need to keep track of open parens, every time we see a closed parens we can sub 1 from count

// we should also keep track of *s, if at the end *count > openParenCount || openParenCount == 0
// we can return true

// if at any point we see a right paren when open count is zero we should sub one from *
// if *count is also zero then ig we can return false


class Solution {
public:
    bool checkValidString(string s) {
        int minOpens = 0, maxOpens = 0;

        for (char c : s) {
            if (c == '(') {
                minOpens++; maxOpens++;
            } else if (c == ')') {
                minOpens--;
                maxOpens--;
            } else {
                minOpens--;
                maxOpens++;
            }
            if (maxOpens < 0) return false;
            if (minOpens < 0) minOpens = 0;
        }
        return minOpens == 0;
    }
};
