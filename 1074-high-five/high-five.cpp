class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> ans;
        map<int, priority_queue<int>> mpq;
        int i, j, n, toAvg, subjects, avg;

        toAvg = 5;
        n = items.size();

        for(i=0; i<n; i++) {
            mpq[items[i][0]].push(items[i][1]);
        }

        for(auto& val: mpq) {
            subjects = toAvg;
            avg = 0;
            while(subjects-- && !mpq.empty()) {
                avg += val.second.top();
                val.second.pop();
            }
            ans.push_back(vector<int>{val.first, avg/toAvg});
        }

        return ans;
    }
};