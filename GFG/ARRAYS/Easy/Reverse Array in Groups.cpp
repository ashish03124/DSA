//
// Created by Agaru on 7/14/2025.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    for (int i=0;i<n;i+=k) {
        int left = i;
        int right = min(i+k-1, n-1);
        while (left<right) {
            swap(arr[left++], arr[right--]);
        }
    }
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;

}