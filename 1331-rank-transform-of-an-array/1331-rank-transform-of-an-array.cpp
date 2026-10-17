// time complexity will be O(nlogn) to sort and tarverse and space compexity will be O(n) for the sorted copy and ans vector 
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> mp;
        int rank = 1;

        for (int i = 0; i < sortedArr.size(); i++) {
            if (mp.find(sortedArr[i]) == mp.end()) {
                mp[sortedArr[i]] = rank;
                rank++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};
