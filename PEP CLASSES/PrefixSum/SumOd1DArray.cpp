//
// Created by Agaru on 1/23/2026.
//
/*
*   Input: nums = [1,2,3,4]
    Output: [1,3,6,10]
    Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> Question_1(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n);
    result[0] = arr[0];
    for (int i=1;i<n;i++) {
        result[i] = result[i-1]+arr[i];
    }
    return result;
}
int main() {
    vector<int> arr = {4,6,1,2,0,3,4,1,2,3,4,6,3,4};
    vector<int> ans = Question_1(arr);
    for (int j : ans)
        cout << j << " ";
    cout << "\n" << endl;
}