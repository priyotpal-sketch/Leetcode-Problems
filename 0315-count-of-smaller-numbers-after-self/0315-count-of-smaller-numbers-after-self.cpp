// Time complexiity of my brute force approach idea in worst case will be O(n^2) that's why this will give time limit constraint
// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, 0);

//         for(int i = 0; i < n; i++) {
//             int count = 0;

//             for(int j = i + 1; j < n; j++) {
//                 if(nums[j] < nums[i]) {
//                     count++;
//                 }
//             }

//             ans[i] = count;
//         }

//         // return ans;
//     }
// };
// this is solution I have taken from AI having time complexity of O(nlogn)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, ans);

        return ans;
    }

    void mergeSort(vector<pair<int, int>>& arr,
                   int left, int right,
                   vector<int>& ans) {

        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, ans);
        mergeSort(arr, mid + 1, right, ans);

        vector<pair<int, int>> temp;

        int i = left;
        int j = mid + 1;
        int smaller = 0;

        while (i <= mid && j <= right) {

            if (arr[j].first < arr[i].first) {
                temp.push_back(arr[j]);
                smaller++;
                j++;
            }
            else {
                ans[arr[i].second] += smaller;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[arr[i].second] += smaller;
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }
};