class Solution {
public:
    #define P_MAX 1000000000000000000

    void print_2d_vector(vector<vector<long long int>> &matrix) {
        for (const auto &row : matrix) {
            for (const auto &element : row) {
                cout << element << " ";
            }
                cout << endl;
        }
    }

    void fill_matrix(vector<int> &a, vector<int>& b, vector<vector<long long int>> &matrix) {
        int a_n, m_n, i, limit, j;

        a_n = a.size(), m_n = matrix[0].size();

        for(i=0; i<a_n; i++) {
            limit = m_n - a_n + i + 1;
            for(j=i; j<limit; j++) {
                if(!i)  matrix[i][j] = ((j)? max(matrix[i][j-1], (long long int)a[i]*b[j]): ((long long int)a[i]*b[j]));
                else    matrix[i][j] = max(matrix[i][j-1], (long long int)a[i]*b[j]+matrix[i-1][j-1]);
            }
        }
    }

    long long int maxScore(vector<int>& a, vector<int>& b) {
        int a_n, b_n;
        int i;

        a_n = a.size(), b_n = b.size();

        vector<vector<long long>> matrix(a_n, vector<long long>(b_n, (long long)-P_MAX));

        fill_matrix(a, b, matrix);

        return matrix[a_n-1][b_n-1];
    }
};