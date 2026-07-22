// The concept here is that we should start counting from the last first occurence of any letter then until any space occurs
class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.length() - 1;

        
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int length = 0;

        
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};