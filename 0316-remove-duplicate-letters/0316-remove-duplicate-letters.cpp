// time complexity of this appraoch will be O(n) as we are visitng each and every character once and space complexity will also be O(n) as we created the stack 
// the concept here is that first count the frequency of each character and then starting pushing the character into stack ,and if a character smaller than the top character of stack appears also at that time in that string there is another same character as stack top is present then just remove the stack top and push smaller character and if later in that string the appearance of that character is 0 then don't remove it ,just add the smaller characters .
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        
        for (char c : s) {
            freq[c - 'a']++;
        }

        string st;

        for (char c : s) {
            freq[c - 'a']--;

            
            if (visited[c - 'a'])
                continue;


            while (!st.empty() &&
                   st.back() > c &&
                   freq[st.back() - 'a'] > 0) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            visited[c - 'a'] = true;
        }

        return st;
    }
};