// the time complexity of this approach will be O(n) as we traversing the text once where n=text.length() and space complexity will be O(1) as we contructed the vector of fixed size .
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for(char c : text) {
            freq[c - 'a']++;
        }

        int count = 0;

        while(freq['b' - 'a'] >= 1 &&
              freq['a' - 'a'] >= 1 &&
              freq['l' - 'a'] >= 2 &&
              freq['o' - 'a'] >= 2 &&
              freq['n' - 'a'] >= 1) {

            freq['b' - 'a']--;
            freq['a' - 'a']--;
            freq['l' - 'a'] -= 2;
            freq['o' - 'a'] -= 2;
            freq['n' - 'a']--;

            count++;
        }

        return count;
    }
};