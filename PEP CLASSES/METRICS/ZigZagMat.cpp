//
// Created by Agaru on 1/23/2026.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> Question_1(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<int> result;
    for (int col=0;col<n+m-1 ; col++) {
        if (col%2==0) {
            int i = min(col, n-1);
            int j = col - i;
            while (i>=0 && j < m) {
                result.push_back(arr[i][j]);
                i++;
                j--;
            }
        }
        else {
            int j = min(col, m-1);
            int i = col - j;
            while (j>=0 && i < n) {
                result.push_back(arr[i][j]);
                i--;
                j++;
            }
        }
        return result;
    }
}
int main() {
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> ans = Question_1(arr);
    for (int j : ans)
        cout << j << " ";
    cout << "\n" << endl;
    return 0;
}