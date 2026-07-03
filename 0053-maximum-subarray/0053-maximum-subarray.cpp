class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int CurrSum=0;
        for(int i=0;i<nums.size();i++){
            CurrSum+=nums[i];
            maxSum=max(maxSum,CurrSum);
            if(CurrSum<0)
            CurrSum=0;
        }
        return maxSum;
    }
};