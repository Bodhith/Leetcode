#define PII pair<int, int>

class Solution {
public:
    struct pair_compare {
        bool operator()(PII& a, PII& b) {
            if (a.second > b.second) {
                return false;
            }
            return true;
        }
    };

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<PII, vector<PII>, pair_compare> min_pq;
        vector<int> ans;
        map<int, int> m;
        int index;

        index = 0;

        for (int val : nums) {
            if (min_pq.size() < k) {
                min_pq.push({index++, -val});
            } else if (val >= -min_pq.top().second) {
                min_pq.pop();
                min_pq.push({index++, -val});
            }
        }

        while (!min_pq.empty()) {
            m[min_pq.top().first] = min_pq.top().second;
            min_pq.pop();
        }

        for (auto& val : m) {
            ans.push_back(-val.second);
        }

        return ans;
    }
};