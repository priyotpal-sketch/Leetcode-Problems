// here []auto a,auto b is just to select the two  elements and comparing them on the basis of frequency which is given out by a.second ,and b.second  
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

       
        for(char c : s) {
            mp[c]++;
        }

       
        vector<pair<char, int>> freq;

        for(auto p : mp) {
            freq.push_back({p.first, p.second});
        }

      
        sort(freq.begin(), freq.end(), [](auto a, auto b) {
            return a.second > b.second;
        });

        
        string ans = "";

        for(auto p : freq) {
            for(int i = 0; i < p.second; i++) {
                ans += p.first;
            }
        }

        return ans;
    }
};