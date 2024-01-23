class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans, toSub, val;
        unordered_map<int, bool> m;
        priority_queue<int, vector<int>, greater<int>> min_pq;

        for(int val: nums) {
            if(!val || m[val]) continue;
            min_pq.push(val);
            m[val] = true;
        }

        toSub = ans = 0;

        while(!min_pq.empty()) {
            toSub += (min_pq.top()-toSub);
            ans++;
            min_pq.pop();
        }

        return ans;
    }
};