// Time complexity here will be O(n+m)
// we are just counting the frequency of each characters in randsom note and for same characters in magazine and if they are equal ,then just return true
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int freq[26] = {0};

        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        for (char ch : ransomNote) {

            freq[ch - 'a']--;

            if (freq[ch - 'a'] < 0)
                return false;
        }

        return true;
    }
};