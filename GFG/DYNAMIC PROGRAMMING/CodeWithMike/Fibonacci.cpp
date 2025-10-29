//
// Created by Agaru on 10/27/2025.
//
//f(n) = f(n-1)+f(n-2) -->
/// dp array will be of direction of number of variables iin the sub-problem
#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int>& dp) {
    if (n<=1) return n;
    if (dp[n]!= -1) {
        return dp[n];
    }
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}
int fibo(int n) {
    if (n==0) return 0;
    if (n==1) return 1;
    vector<int> dp(n+1, -1);

    return solve(n, dp);
}
// int solution(int n) {
//     if (n<=1) return n;
//     int c;
//     int a = 0, b = 1;
//     for (int i = 1; i<=n;i++) {
//         c = a+b;
//         a = b;
//         b = c;
//     }
//     return c''
// }
int main() {
    cout << "enter a number: " << endl;
    int n;
    cin >> n;
    // if (n<=1) return n;
    // vector<int> dp(n+1,-1);
    // dp[0] = 0;
    // dp[1] = 1;
    // for (int i=2;i<=n;i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout << dp[n] << endl;

    cout << fibo(n) << endl;
    return 0;
}