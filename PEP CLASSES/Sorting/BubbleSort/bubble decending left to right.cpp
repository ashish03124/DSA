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

    for (int i = 0 ; i < n ; i++) {
        cout << i + 1 << ":\n";
        for (int j = n-i; j >=0 ; j--) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cout << " Swap ";
                for (int k = 0; k < n; k++) cout << arr[k] << " ";
                cout << endl;
            } else {
                cout << " No\n";
            }
        }
        cout << endl;
    }

    cout << "Final: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
