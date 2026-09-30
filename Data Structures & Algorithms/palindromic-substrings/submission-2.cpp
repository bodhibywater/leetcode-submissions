/* pretty much same approach as last question, but instead of updating res & resLen,
we update a counter every time l & r are inc/dec

*/

class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0;
        for (int i = 0; i < s.size(); i++) {
            counter += countPali(s, i, i);
            counter += countPali(s, i, i+1);
        }
        return counter;
    }
private:
    int countPali(string s, int l, int r) {
        int counter = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            counter++;
            l--;
            r++;
        }
        return counter;
    }
};
