// time complexity will be O(n) here we traversing the loop fromstart to end and space complexity will be O(K) where is K the number  of characters in string and we created a map .
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {

            // s -> t mapping
            if (mp1.find(s[i]) != mp1.end()) {
                if (mp1[s[i]] != t[i])
                    return false;
            }

            // t -> s mapping
            if (mp2.find(t[i]) != mp2.end()) {
                if (mp2[t[i]] != s[i])
                    return false;
            }

            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        return true;
    }
};
