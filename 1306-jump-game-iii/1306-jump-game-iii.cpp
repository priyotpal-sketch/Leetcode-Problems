// Time complexity will be O(n) as we will try to visit every indices
// we are marking every indices after visiting them because we don't want to  create a infinite loop ,so after visiting them check  whether they are equal  0 or not and then try for jumping index . 
class Solution {
public:
    bool dfs(vector<int>& arr, int index) {

    
        if (index < 0 || index >= arr.size())
            return false;

        
        if (arr[index] == -1)
            return false;

        
        if (arr[index] == 0)
            return true;

        int jump = arr[index];
        arr[index] = -1;

        
        return dfs(arr, index + jump) ||
               dfs(arr, index - jump);
    }

    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }
};