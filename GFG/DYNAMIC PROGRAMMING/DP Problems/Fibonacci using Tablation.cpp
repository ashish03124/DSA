//
// Created by Agaru on 8/26/2025.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int pre2 = 0;
    int pre1 = 1;
    for (int i=2;i<=n;i++) {
        int curr = pre1 + pre2;
        pre2 = pre1;
        pre1 = curr;
    }
    cout << pre1;
}