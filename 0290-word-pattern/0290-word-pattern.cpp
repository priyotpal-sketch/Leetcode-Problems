// Time complexity of this approach will be O(n) as we traversing each word and each chracter also the space complexity will be O(n)
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;

        
        for(char c : s) {
            if(c == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }

        words.push_back(word);

       
        if(pattern.size() != words.size())
            return false;

        map<char, string> charToWord;
        map<string, char> wordToChar;

        for(int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];
            string w = words[i];

           
            if(charToWord.count(ch)) {
                if(charToWord[ch] != w)
                    return false;
            }

            
            if(wordToChar.count(w)) {
                if(wordToChar[w] != ch)
                    return false;
            }

            
            charToWord[ch] = w;
            wordToChar[w] = ch;
        }

        return true;
    }
};