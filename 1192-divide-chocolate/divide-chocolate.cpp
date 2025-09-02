class Solution {
public:
    #define LIMIT 100001
    
    int findMaxSweetnessWithK(int k, vector<int> &a) {
        int i, n, maxiSweet;

        if(k < 2) k = 2;

        for(i=k-2, maxiSweet=0, n=a.size(); i<n; i++) maxiSweet += a[i];

        return maxiSweet;
    }

    bool can_achieve(int sweetness, int parts, vector<int> &a) {
        int i, n, partSweet;

        for(i=partSweet=0, n=a.size(); i<n; i++) {
            partSweet += a[i];
            if(partSweet >= sweetness) {
                parts -= 1;
                partSweet = 0;
                if(parts == 0) {
                    break;
                }
            }
        }

        if(parts) return false;

        return true;
    }

    int maxiSweetness(vector<int> &a, int k) {
        int left, right, mid;
        bool isValid;
        vector<int> sortedA;

        sortedA = a;
        sort(sortedA.begin(), sortedA.end());

        left = sortedA[0];
        right = findMaxSweetnessWithK(k, sortedA);

        while(left <= right) {
            mid = left + (right-left)/2;
            
            isValid = can_achieve(mid, k, a);

            if(left == right and isValid) return mid;

            if(isValid) left = mid + 1;
            else right = mid - 1;
        }

        return mid - 1;
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {
        int ans = maxiSweetness(sweetness, k+1);
        // int ans = can_achieve(1, 8, sweetness);
        return ans;
    }
};