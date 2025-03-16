class Solution {
public:
    int climbStairs(int n) {
        int size;

        if( n < 2 )    size = 2;
        else    size = n;

        vector<int> dp(size+1, 0);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};