//
// Created by Agaru on 11/7/2025.
//
#include <bits/stdc++.h>
using namespace std;
int missingnumber(vector<int> arr) {
    int sum =0;
    int sum1 =0;

    int n = arr.size();
    for (int num : arr) {
        sum += num;
    }
    for (int i=0;i<=n+1;i++) {
        sum1 += i;
    }
    return sum1 - sum;
}
int main() {
    vector<int> arr(9);
    for (int i=0;i<9;i++) {
        cin >> arr[i];
    }
cout  << missingnumber(arr);
}