//
// Created by Agaru on 11/12/2025.
//
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> t(n + 1, vector<int>(m + 1, INT_MAX));

        t[n][m - 1] = 1;
        t[n - 1][m] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int minHealth = min(t[i + 1][j], t[i][j + 1]) - arr[i][j];
                t[i][j] = max(1, minHealth);
            }
        }
        return t[0][0];
    }
};
