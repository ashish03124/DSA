//
// Created by Agaru on 7/14/2025.
//
#include <bits/stdc++.h>
using namespace std;
//ROTATING ARRAY BASED ON THE INDEX
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i=0;i<n;i++) {
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     vector<int> temp;
//     for (int i=k;i<n;i++) {
//         temp.push_back(arr[i]);
//     }
//     for (int i=0;i<k;i++) {
//         temp.push_back(arr[i]);
//     }
//     for (int i : temp) {
//         cout << i << " ";
//     }
//     return 0;
// }
//ROTATING ARRAY n TIMES
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int m = k;
    if (k  > n) {
        m = k%n;
    }
    vector<int> temp;
    for (int i=m;i<n;i++) {
        temp.push_back(arr[i]);
    }
        for (int j = 0; j< m;j++) {
            temp.push_back(arr[j]);
        }

    for (int i : temp) {
        cout << i << " ";
    }
}