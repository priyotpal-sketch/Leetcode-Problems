// time complexity here will be O(m*n) where n =number of words  and m is average length of words 
// this question approach is similar as 383 question number
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        int charFreq[26] = {0};

        for (char ch : chars) {
            charFreq[ch - 'a']++;
        }

        int ans = 0;

        for (string word : words) {

            int wordFreq[26] = {0};

            for (char ch : word) {
                wordFreq[ch - 'a']++;
            }

            bool possible = true;

            for (int i = 0; i < 26; i++) {

                if (wordFreq[i] > charFreq[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans += word.length();
            }
        }

        return ans;
    }
};