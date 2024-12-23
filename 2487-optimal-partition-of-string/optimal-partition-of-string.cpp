class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        unordered_map<char, bool> m;

        for(char c: s) {
            if(!m[c]) {
                m[c] = true;
                if(!ans) ans++;
            }
            else {
                m.clear();
                m[c] = true;
                ans++;
            }
        }

        return ans;
    }
};