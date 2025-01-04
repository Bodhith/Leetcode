class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n, left, right, mid;

        n = nums.size();

        left = 0, right = n-1;

        while(left <= right) {
            mid = left + (right - left)/2;
            if(target == nums[mid])   return mid;
            else if(target > nums[mid])    left = mid + 1;
            else    right = mid - 1;
        }

        return -1;
    }
};