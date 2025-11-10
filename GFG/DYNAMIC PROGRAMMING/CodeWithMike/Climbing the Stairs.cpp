#include <bits/stdc++.h>
using namespace std;

int t[201][201]; // memo table
int n;

int solve(vector<vector<int>> &matrix, int r, int c) {
    // out of bounds
    if (c < 0 || c >= n) return INT_MAX;

    // base case: last row
    if (r == n - 1) return matrix[r][c];

    // memo check
    if (t[r][c] != -1) return t[r][c];

    // recursive exploration
    int down = solve(matrix, r + 1, c);
    int left = solve(matrix, r + 1, c - 1);
    int right = solve(matrix, r + 1, c + 1);

    // store and return
    return t[r][c] = matrix[r][c] + min({down, left, right});
}

int main() {
    vector<vector<int>> matrix = {
        {2, 5, 3},
        {6, 7, 4},
        {1, 8, 9}
    };

    n = matrix.size();
    memset(t, -1, sizeof(t));

    int result = INT_MAX;
    for (int c = 0; c < n; c++) {
        result = min(result, solve(matrix, 0, c));
    }

    cout << "Minimum Falling Path Sum: " << result << endl;
    return 0;
}
