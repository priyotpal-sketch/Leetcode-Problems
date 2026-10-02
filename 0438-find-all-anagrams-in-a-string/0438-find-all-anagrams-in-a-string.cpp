// this is my brute force approach idea, time complexity of this approach is  O(n*mlogm) and space complexity will be O(m) but this will give a time limit problem
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
        
//         if (s.length() < p.length())
//             return ans;

//         string sortedP = p;
//         sort(sortedP.begin(), sortedP.end());

//         int k = p.length();

//         for (int i = 0; i <= s.length() - k; i++) {
//             string temp = s.substr(i, k);
//             sort(temp.begin(), temp.end());

//             if (temp == sortedP)
//                 ans.push_back(i);
//         }

//         return ans;
//     }
// };
// this is optimal solution for this probelm using sliding window approach whose time complexiy will be O(n) and space complexity will be O(1) where n is length of s string 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (s.size() < p.size())
            return ans;

        vector<int> freq(26, 0);

      
        for (char c : p)
            freq[c - 'a']++;

        int left = 0;
        int right = 0;
        int count = p.size();

        while (right < s.size()) {
           
            if (freq[s[right] - 'a'] > 0)
                count--;

            freq[s[right] - 'a']--;
            right++;

            if (right - left > p.size()) {
                if (freq[s[left] - 'a'] >= 0)
                    count++;

                freq[s[left] - 'a']++;
                left++;
            }

            
            if (count == 0)
                ans.push_back(left);
        }

        return ans;
    }
};

