class Solution {
public:
    #define RIGHT_LIMIT 10000

    void printVectorInt(vector<int> &a) {
        for(int &val: a) {
            cout << val << ' ';
        }
        cout << '\n';
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> md_st;
        vector<int> next_greater_elements(nums2.size(), -1);
        vector<int> hash(RIGHT_LIMIT+1, -1);
        vector<int> ans;
        int i, n;

        for(i=0, n=nums2.size(); i<n; i++) {
            while(!md_st.empty() and nums2[md_st.top()] < nums2[i]) {
                next_greater_elements[md_st.top()] = nums2[i];
                md_st.pop();
            }
            md_st.push(i);
        }

        //printVectorInt(next_greater_elements);

        i = 0;

        for(int &val: nums2)    hash[val] = next_greater_elements[i++];

        for(int &val: nums1)    ans.push_back(hash[val]);

        return ans;
    }
};