//
// Created by Agaru on 8/13/2025.
//
#include <bits/stdc++.h>
using namespace std;
int S;
int solve(vector<int> &arr,int t, int i,int cs, vector<vector<int>> &dp) {
    if (i==arr.size()) {
        if (cs==t) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dp[i][cs+S]!=-1) return dp[i][cs+S];

    int plus = solve(arr,t, i+1, cs+arr[i],dp);
    int minus = solve(arr,t, i+1, cs-arr[i],dp);
    return dp[i][cs+S] = plus + minus;
}

int main() {
    vector<int> arr = {1,1,1,1,1};
    int n = arr.size();
    int t = 3;
    S = accumulate(begin(arr),end(arr),0);
    vector<vector<int>> dp(n+1, vector<int>(2*S,-1));
    int result = 0;
    result = solve(arr, t, 0 , 0, dp);
    cout << result << endl;
    return 0;
}