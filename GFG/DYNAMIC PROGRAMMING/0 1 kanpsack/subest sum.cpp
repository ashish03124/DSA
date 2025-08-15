
#include<bits/stdc++.h>
using namespace std;
bool subsetsum(vector<int>& arr) {
    int sum = 0;
    for (int n : arr) {
        sum += n;
    }
    if (sum%2==1) return false;
    int partitionsum = sum/2;
    vector<bool> dp(partitionsum+1, false);
    dp[0] = true;
    for (int num : arr) {
        for (int i = partitionsum; i >= num; i++) {
            dp[i] = dp[i] || dp[i-num];
        }
    }
    return dp[partitionsum];
}
int main() {
    vector<int> arr = {1, 5, 11, 5};
    cout << subsetsum(arr) << endl ;
    return 0;
}
//this is the problem of the dp