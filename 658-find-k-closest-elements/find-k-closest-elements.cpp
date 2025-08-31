class Solution {
public:

    int binary_search(vector<int> &a, int x) {
        int n, left, right, mid;
        
        n = a.size();
        left = 0, right = n;
        
        while (left < right) {
            mid = left + (right-left)/2;
            if (a[mid] > x) {
                right = mid;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                left = right = mid;
            }
        }

        return left;
    }

    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        vector<int> ans;
        int pos, n, pl, pr;

        n = a.size();
        pos = binary_search(a, x);

        //cout << pos << " , " << a[pos];

        pl = pos - 1;
        pr = pos;

        while (pr - pl - 1 < k) {
            if (pl == -1) {
                pr += 1;
                continue;
            }

            if (pr == a.size() or abs(a[pl]-x) <= abs(a[pr]-x)) {
                pl -= 1;
            } else {
                pr += 1;
            }
        }

        while(k--) {
            ans.push_back(a[++pl]);
        }
        
        return ans;
    }
};


































