// time compexity here will be O(n) bcoz we are visiting every character of string once 
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};