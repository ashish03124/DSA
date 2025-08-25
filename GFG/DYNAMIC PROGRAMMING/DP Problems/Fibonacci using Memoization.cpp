//
// Created by Agaru on 8/26/2025.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;  // memoization array

int fibbo(int n) {
    if (arr[n] != -1) return arr[n];  // already computed

    if (n == 0 || n == 1) return arr[n] = n;  // base case

    arr[n] = fibbo(n-1) + fibbo(n-2);  // recursion + memoization
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    arr.assign(n+1, -1);   // initialize memo array with -1

    for (int i = 0; i < n; i++) {
        cout << fibbo(i) << " ";  // print series
    }
    cout << endl;

    return 0;
}
