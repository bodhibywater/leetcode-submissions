class Solution {
public:
    bool isPalindrome(string s) {
        //Input: A string made up of any printable ASCII characters
        //Task: To check if the string with all non=alphanumeric characters removed is a palindfrome
        
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            while (start < end && !alphaNum(s[start])) {
                start++;
            }
            while(end > start && !alphaNum(s[end])) {
                end--;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++; end--;
        }
        return true;

    }

    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
