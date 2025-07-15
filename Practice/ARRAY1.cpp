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
    for (int i=0;i<n;i++) {
        int left = i;
        int right  = max_element(arr.begin() + i, arr.end()) - arr.begin();
        while (left < right) {
            swap(arr[left++], arr[right--]);
        }
    }
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}