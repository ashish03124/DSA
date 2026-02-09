//
// Created by Agaru on 1/24/2026.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {1,2,3,4,5};
    int n = 5;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n\n";
    for (int i=n-1;i>=0;i--) {
        cout << i+1 << ":" << "\n";
        int misa = i;
        for (int j=i-1;j>=0;j--) {
            if (arr[j]<arr[misa]) {
                misa = j;
            }
            for (int k=0;k<n;k++) cout << arr[k] << " ";
            cout << "\n";
        }
        if (misa!=i) {
            swap(arr[i],arr[misa]);
            cout << "  Swapping " << arr[misa] << " with " << arr[i] <<"\n" ;
        }
    }
    cout << "Final: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}