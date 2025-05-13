class Solution {
public:
    int search(vector<int>& a, int target) {
        int n, l, r, mid;

        n = a.size();

        l = 0;
        r = n-1;

        while(l <= r) {
            mid = l + (r-l)/2;

            if(a[mid] == target) {
                return mid;
            }

            if(a[mid] < target) {
                l = mid + 1;
            } else if(a[mid] > target) {
                r = mid - 1;
            }
        }

        return -1;
    }
};