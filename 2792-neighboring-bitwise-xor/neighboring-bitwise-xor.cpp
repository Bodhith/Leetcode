class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for(int val: derived)   ans = ans ^ val;
        return ans == 0;
    }
};