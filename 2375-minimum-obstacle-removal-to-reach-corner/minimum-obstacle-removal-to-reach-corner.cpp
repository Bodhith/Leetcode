class Solution {
public:

    bool isValidMove(int i, int j, int n, int m) {
        if(i >= 0 and i < n and j >= 0 and j < m)
            return true;
        return false;
    }

            // if(isValidMove(i+1, j, n, m)) {
            //     haveIVisitedItBefore[i+1][j] = true;
            // }
            // if(isValidMove(i, j+1, n, m)) {
            //     haveIVisitedItBefore[i][j+1] = true;
            // }
            // if(isValidMove(i-1, j, n, m)) {
            //     haveIVisitedItBefore[i-1][j] = true;
            // }
            // if(isValidMove(i, j-1, n, m)) {
            //     haveIVisitedItBefore[i][j-1] = true;
            // }

    int minimumObstacles(vector<vector<int>>& grid) {
        tuple<int, int, int> tt;
        int i, j, o, to, n, m;

        o = 0;
        n = grid.size(), m = grid[0].size();

        vector<vector<bool>> haveIVisitedItBefore(n, vector<bool>(m, false));
        deque<tuple<int, int, int>> dq;

        dq.push_back(make_tuple(0, 0, 0));

        while( !dq.empty() ) {
            tt = dq.front();
            i = get<0>(tt), j = get<1>(tt), o =  get<2>(tt);

            if(i == n-1 and j == m-1)   return o;

            dq.pop_front();

            if( haveIVisitedItBefore[i][j] )    continue;

            haveIVisitedItBefore[i][j] = true;

            if(isValidMove(i+1, j, n, m)) {
                if( grid[i+1][j] )  dq.push_back(make_tuple(i+1, j, o+1));
                else                dq.push_front(make_tuple(i+1, j, o));
            }
            if(isValidMove(i, j+1, n, m)) {
                if( grid[i][j+1] ) dq.push_back(make_tuple(i, j+1, o+1));
                else               dq.push_front(make_tuple(i, j+1, o));
            }
            if(isValidMove(i-1, j, n, m)) {
                if( grid[i-1][j] )  dq.push_back(make_tuple(i-1, j, o+1));
                else                dq.push_front(make_tuple(i-1, j, o));
            }
            if(isValidMove(i, j-1, n, m)) {
                if( grid[i][j-1] ) dq.push_back(make_tuple(i, j-1, o+1));
                else               dq.push_front(make_tuple(i, j-1, o));
            }
            
        }

        return o;
    }
};