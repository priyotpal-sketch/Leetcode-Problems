// time complexit willbe O(n*L) WHERE L is length of largest generated string and sapce complexity will be O(L) for strings used to construct each term  
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++) {
            string ans = "";
            int j = 0;

            while (j < s.length()) {
                int count = 1;

                while (j + 1 < s.length() && s[j] == s[j + 1]) {
                    count++;
                    j++;
                }

                ans += to_string(count);
                ans += s[j];
                j++;
            }

            s = ans;
        }

        return s;
    }
};
