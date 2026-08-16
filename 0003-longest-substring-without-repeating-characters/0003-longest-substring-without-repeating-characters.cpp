// Time complextity here will be O(n) 
// Notice on the differencebwteen subsequence and substring
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {

            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            maxLength = max(maxLength,
                            right - left + 1);
        }

        return maxLength;
    }
};