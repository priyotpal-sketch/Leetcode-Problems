// Time complexity will be O(n)
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        
        for(int x : nums) {
            st.insert(x);
        }

    
        int multiple = k;

        while(true) {

            if(st.find(multiple) == st.end()) {
                return multiple;
            }

            multiple += k;
        }
    }
};