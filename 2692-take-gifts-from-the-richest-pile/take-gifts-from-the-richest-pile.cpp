class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long int ans;
        priority_queue<int> max_pq;

        ans = 0;

        for(int gift: gifts) {
            max_pq.push(gift);
        }

        while(k-- and !max_pq.empty()) {
            max_pq.push(sqrt(max_pq.top()));
            max_pq.pop();
        }

        while(!max_pq.empty()) {
            ans += max_pq.top();
            max_pq.pop();
        }

        return ans;
    }
};