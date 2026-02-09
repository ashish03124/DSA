//
// Created by Agaru on 1/23/2026.
//
/*
*   Input: gain = [-5,1,5,0,-7]
    Output: 1
    Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
*/
#include <bits/stdc++.h>
using namespace std;
int largestAltitude(vector<int>& gain) {
    int n = gain.size()+1;
    vector<int> result(n+1);
    result[0] = 0;
    for(int i=0;i<n;i++){
        result[i+1] = result[i]+gain[i];
    }
    int m = *max_element(result.begin(),result.end());
    return m;
}
int main() {
    vector<int> arr = {-5,1,5,0,-7};
    cout << largestAltitude(arr) << endl;
}