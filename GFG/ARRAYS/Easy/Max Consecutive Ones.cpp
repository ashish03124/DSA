//
// Created by Agaru on 7/14/2025.
//
#include <bits/stdc++.h>
using namespace std;
//SIMPLE TRAVERSAL
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i=0;i<n;i++) {
//         cin >> arr[i];
//     }
//     int c = 1;
//     int mc = 0;
//     for (int i=0;i<n;i++) {
//         if (arr[i] == arr[i-1]) {
//             c++;
//         }
//         else {
//             mc = max(mc, c);
//             c = 1;
//         }
//     }
//     cout << max(mc,c);
//     return 0;
//
//
// }
//BIT MANUPULATION
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int c = 0;
    int mc = 0;
    int prev = -1;
    for (int a : arr) {
        if ((prev ^ a) ==0) {
            c++;
        }
        else {
            mc = max(mc, c);
            c = 1;
        }
        prev = a;
    }
    cout << max(mc,c);
    return 0;


}