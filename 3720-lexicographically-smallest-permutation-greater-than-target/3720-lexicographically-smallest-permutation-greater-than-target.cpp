class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // We can use target[i]
            if (freq[x] > 0) {
                freq[x]--;
            }
            else {

                // Cannot match target[i].
                // Try the smallest character greater than target[i].
                for (int j = x + 1; j < 26; j++) {

                    if (freq[j] > 0) {

                        string ans = target.substr(0, i);

                        // Make the string greater here
                        ans += char('a' + j);
                        freq[j]--;

                        // Put remaining characters in sorted order
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                ans += char('a' + k);
                                freq[k]--;
                            }
                        }

                        return ans;
                    }
                }

                // No bigger character available.
                // Backtrack to previous positions.
                for (int p = i - 1; p >= 0; p--) {

                    // Put target[p] back
                    int y = target[p] - 'a';
                    freq[y]++;

                    // Find smallest character > target[p]
                    for (int j = y + 1; j < 26; j++) {

                        if (freq[j] > 0) {

                            string ans = target.substr(0, p);

                            ans += char('a' + j);
                            freq[j]--;

                            // Remaining characters in sorted order
                            for (int k = 0; k < 26; k++) {
                                while (freq[k] > 0) {
                                    ans += char('a' + k);
                                    freq[k]--;
                                }
                            }

                            return ans;
                        }
                    }
                }

                return "";
            }
        }

        // We matched the entire target exactly.
        // So we must backtrack and make some position bigger.
        for (int p = n - 1; p >= 0; p--) {

            // Put target[p] back
            int x = target[p] - 'a';
            freq[x]++;

            // Find smallest character greater than target[p]
            for (int j = x + 1; j < 26; j++) {

                if (freq[j] > 0) {

                    string ans = target.substr(0, p);

                    ans += char('a' + j);
                    freq[j]--;

                    // Remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};