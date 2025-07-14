//
// Created by Agaru on 7/14/2025.
//
#include <bits/stdc++.h>
using namespace std;
//SORTING
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i=0;i<n;i++) {
//         cin >> arr[i];
//     }
//     sort(arr,arr+n);          //O( n log n )
//     cout << arr[n-2];
//     return 0;
// }
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
//     cout << SMax << endl;
//
// }
//ONE PASS SEARCH
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int Max = 0;
    int SMax = 0;
    for (int i=0;i<n;i++) {
        if (arr[i] > Max) {
            SMax =Max;
            Max = arr[i];
        }
        else if (arr[i] < Max && arr[i] > SMax) {
            SMax = arr[i];
        }
    }
    cout << SMax << endl;
}