/* Given a string s
We need to return longest substring that is a palindrome

Palindrome when symmetric

We can iterate through, and treat char with index i as the center of an odd palindrome.
Then extend to look at the left and righr chars, if left == right we update result vars

We should keep two result variables, resLen: (stores len of longest palin) and res:
(stores start index of longest palin)

If ever (i + 1) char == i char, then we should also check for even palindromes, 
maybe make a helper func to do this and call it when necessary. 

Two pointers approach
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0, res = 0;

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    res = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r-l+1 > resLen) {
                    resLen = r-l+1;
                    res = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(res, resLen);
    }

};
