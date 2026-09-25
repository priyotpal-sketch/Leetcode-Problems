// time complexity will be O(n) and space complexity will also be O(n) as we are creating a unordered map 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        
        for(int x : nums) {
            mp[x]++;
        }

        int duplicate = -1;
        int missing = -1;

      
        for(int i = 1; i <= n; i++) {
            if(mp[i] == 2)
                duplicate = i;

            if(mp[i] == 0)
                missing = i;
        }

        return {duplicate, missing};
    }
};