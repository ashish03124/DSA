//
// Created by Agaru on 1/24/2026.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {5,4,8,2,1};
    int n = arr.size();
    cout << "initial" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    for (int i=0;i<n-1;i++) {
        for (int j=i;j<n-i-1;j++) {
            if (arr[j]>arr[j+1]) {
                    swap(arr[j], arr[j + 1]);
                    cout << " Swap ";
                    for (int k = 0; k < n; k++) cout << arr[k] << " ";
                    cout << endl;
                } else {
                    cout << " → No swap\n";
            }
        }
    }

}