class Solution {
public:

    map<int, int> memo;

    int can_split_recursive(int max_sum, int max_operations, int val) {
        if (val <= max_sum) return 0;
        else if (memo[val]) return memo[val];

        int leftOperations, rightOperations;

        leftOperations = rightOperations = 0;
        
        leftOperations = can_split_recursive(max_sum, max_operations, val - max_sum);

        if (leftOperations == -1) return -1;
        if (leftOperations + rightOperations > max_operations) return -1;

        memo[floor(val/2.0)] = leftOperations;

        // rightOperations = can_split_recursive(max_sum, max_operations, ceil(val/2.0));

        // if (rightOperations == -1) return -1;
        if (leftOperations + rightOperations > max_operations) return -1;

        // memo[ceil(val/2.0)] = rightOperations;

        return leftOperations + rightOperations + 1;
    }

    int can_split(int max_sum, int max_operations, int val) {
        if(val <= max_sum) return 0;

        int operations;

        if(val%max_sum == 0) operations = val/max_sum - 1;
        else operations = val/max_sum;

        if(operations > max_operations) return -1;

        return operations;
    }

    bool can_achieve(int max_sum, int max_operations, vector<int> &a) {
        int i, n, operations;

        operations = 0;
        n = a.size();
        i = n-1;

        while(i >= 0) {
            operations = can_split(max_sum, max_operations, a[i]);
            
            if(operations == -1) return false;
            
            max_operations -= operations;
            operations = 0;

            if(max_operations < 0) return false;

            i -= 1;
        }

        return true;
    }

    int minSize(vector<int> &a, int maxOperations) {
        int left, right, n, mid, operations;

        n = a.size();
        sort(a.begin(), a.end());

        left = 1;
        right = a[n-1]+1;

        while(left < right) {
            mid = left + (right-left)/2;

            if(can_achieve(mid, maxOperations, a)) right = mid;
            else left = mid + 1;
        }

        return right;
    }

    int minimumSize(vector<int>& a, int maxOperations) {
        int operations = minSize(a, maxOperations);
        return operations;
    }
};