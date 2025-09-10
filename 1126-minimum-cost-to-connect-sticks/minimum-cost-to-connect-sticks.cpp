class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> min_pq;
        int ans, x, y;

        for(int& val: sticks) {
            min_pq.push(val);
        }

        ans = 0;

        while(min_pq.size() >= 2) {
            x = min_pq.top();
            min_pq.pop();
            y = min_pq.top();
            min_pq.pop();

            ans += x + y;

            min_pq.push(x+y);
        }

        return ans;
    }
};