// time complexity will be O(n+m) and space complexity will be O(1) as we using here two pointers approach so did'nt need extra space 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};