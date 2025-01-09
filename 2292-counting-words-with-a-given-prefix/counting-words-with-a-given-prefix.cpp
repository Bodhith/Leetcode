class Solution {
public:
    int findStr(string a, string b) {
        if(b.size() > a.size()) return -1;

        int i, n;

        for(i=0, n=a.size(); i<n; i++) {
            if(i == b.size())  return i;
            if(a[i] != b[i])   return -1;
        }
        
        return i;
    }

    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(string word: words) {
            if(findStr(word, pref) != -1)   ans++;
        }

        return ans;
    }
};