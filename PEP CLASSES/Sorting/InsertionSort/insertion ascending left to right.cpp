//
// Created by Agaru on 1/24/2026.
//
#include <bits/stdc++.h>
using namespace std;
int main () {
    int arr[] = {14, 13, 7, 15, 2, 6};
    int n = 6;
    for (int i=1;i<n;i++) {
        cout << i << endl;
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            cout << arr[j] << " with " << arr[j-1] << "\n";
            j--;
        }
        arr[j+1] = key;

    }
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
}