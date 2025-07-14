//
// Created by Agaru on 7/14/2025.
//
#include <bits/stdc++.h>
using namespace std;
//USING EXTRA SPACE O(N)
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i=0;i<n;i++) {
//         cin >> arr[i];
//     }
//     vector<int> temp;
//     for (int i=0;i<n;i++) {
//         if (arr[i]!=0) {
//             temp.push_back(arr[i]);
//         }
//     }
//     for (int i=0;i<n;i++) {
//         if (arr[i]==0) {
//             temp.push_back(arr[i]);
//         }
//     }
//     for (int i=0;i<n;i++) {
//         cout << temp[i] << " ";
//     }
//     return 0;
// }

//TWO TRAVERSAL
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i=0;i<n;i++) {
//         cin >> arr[i];
//     }
//     int count = 0;
//     for (int i=0;i<n;i++) {
//         if (arr[i] != 0) {
//             arr[count++] = arr[i];
//         }
//     }
//     while (count < n) {
//         arr[count++] = 0;
//     }
//     for (int i=0;i<n;i++) {
//         cout << arr[i] << " ";
//     }
// }

//ONE TRAVERSAL
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i=0;i<n;i++) {
//         cin >> arr[i];
//     }
//     int count = 0;
//     for (int i=0;i<n;i++) {
//         if (arr[i]!=0) {
//             swap(arr[i], arr[count]);
//             count++;
//         }
//     }
//     for (int i=0;i<n;i++) {
//         cout << arr[i] << " ";
//     }
// }
//USING STANDARD LIBRARY
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    stable_partition(arr.begin(), arr.end(), [](int n){ return n != 0;
});
    for (int x : arr) {
        cout << x << " ";
    }
}
