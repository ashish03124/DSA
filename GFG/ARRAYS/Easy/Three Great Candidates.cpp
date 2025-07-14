//
// Created by Agaru on 7/14/2025.
//

#include <bits/stdc++.h>
using namespace std;
//SORTING
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);          //O( n log n )
    cout << arr[n-3]*arr[n-2]*arr[n-1];
    return 0;
}
//TWO PASS SEARCH
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i=0;i<n;i++) {
//         cin >> arr[i];
//     }
//     int Max = 0;
//     int SMax = 0;
//     int TMax = 0;
//     for (int i=0;i<n;i++) {
//         if (arr[i] > Max) {
//             Max = arr[i];
//          }
//     }
//     for (int i=0;i<n;i++) {               //O( n )
//         if (arr[i] > SMax && arr[i] != Max) {
//             SMax = arr[i];
//         }
//     }
//     for (int i=0;i<n;i++) {
//         if (arr[i] >TMax && arr[i] != SMax && arr[i] != Max) {
//             TMax = arr[i];
//         }
//     }
//     cout << TMax*SMax*Max<< endl;
//
// }
//ONE PASS SEARCH
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i=0;i<n;i++) {
//         cin >> arr[i];
//     }
//     int Max = -1;
//     int SMax = -1;
//     int TMax = -1;
//     for (int i=0;i<n;i++) {
//         if (arr[i] > Max) {
//             TMax = SMax;
//             SMax = Max;
//             Max = arr[i];
//         }
//         else if (arr[i] < Max && arr[i] > SMax) {
//             TMax = SMax;
//             SMax = arr[i];
//         }
//         else if (arr[i] < SMax && arr[i] > TMax) {
//             TMax = arr[i];
//         }
//     }
//     cout << TMax*SMax*Max << endl;
// }