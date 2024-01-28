class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int i, n, left, mid, right;
        
        n = a.size();
        
        left = 0;
        right = n-1;
        
        if(n == 1) {
            return 0;
        } else if(n == 2) {
            if(a[left] > a[right]) {
                return left;
            } else {
                return right;
            }
        }
        
        while(left <= right) {
            mid = left + (right-left)/2;
            
            if(mid > 0 and mid < n-1) {
                if(a[mid] > a[mid-1] and a[mid] > a[mid+1]) {
                    return mid;
                }
            } else {
                if(mid == 0) {
                    if(a[mid] > a[mid+1]) return mid;
                    return mid+1;
                } else if(mid==n-1) {
                    if(a[mid] > a[mid-1]) return mid;
                    return mid-1;
                }
            }
            
            if(a[mid-1] > a[mid+1]) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return 0;
    }
};