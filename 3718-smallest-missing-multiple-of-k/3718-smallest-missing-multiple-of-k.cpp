class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        // Store all numbers
        for(int x : nums) {
            st.insert(x);
        }

        // Check multiples of k
        int multiple = k;

        while(true) {

            if(st.find(multiple) == st.end()) {
                return multiple;
            }

            multiple += k;
        }
    }
};