class Solution {
public:

    vector<int> modifiedNextGreaterElement(vector<int> &nums2) {
        stack<int> md_st;
        vector<int> next_greater_elements(nums2.size(), -1);
        map<int, bool> hasInStack;
        int i, n;

        for(i=0, n=nums2.size(); ; i++) {
            if(i == n)  i = 0;

            while(!md_st.empty() and nums2[md_st.top()] < nums2[i]) {
                next_greater_elements[md_st.top()] = nums2[i];
                hasInStack[md_st.top()] = false;
                md_st.pop();
            }

            if(hasInStack[i])   break;

            md_st.push(i);

            hasInStack[i] = true;
        }

        return next_greater_elements;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        return modifiedNextGreaterElement(nums);
    }
};