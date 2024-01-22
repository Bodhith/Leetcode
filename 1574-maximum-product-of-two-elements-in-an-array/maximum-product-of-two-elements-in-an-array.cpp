class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int A, B;
        priority_queue<int> pq;

        for(int val: nums) {
            pq.push(val);
        }

        A = pq.top();
        pq.pop();
        B = pq.top();

        return --A * --B;
    }
};