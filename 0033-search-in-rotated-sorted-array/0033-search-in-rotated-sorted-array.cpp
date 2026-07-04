class Solution {
public:
    int targetsearch(vector<int>&nums,int st,int end,int target){
        int mid=st+(end-st)/2;
        if(st>end){
            return -1;
        }
        
        if(target==nums[mid]){
            return mid;
        }
        if(nums[st]<=nums[mid]){
            if(nums[st]<=target && target<nums[mid]){
               return  targetsearch(nums,st,mid-1,target);
            }else{
               return  targetsearch(nums,mid+1,end,target);
            }
        }
        else
        {
            if(nums[mid]<target && target<=nums[end]){
               return targetsearch(nums,mid+1,end,target);

            }else{
                return targetsearch(nums,st,mid-1,target);
            }
        }
        }
    
    int search(vector<int>& nums, int target) {
        
        return targetsearch(nums,0,nums.size()-1,target);
    }
};