//
// Created by Agaru on 7/20/2025.
// array can store 10^6 int values(inside main, and for global 10^7) and , 10^7 char values(inside main, 10^8 for global)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int hash[103] = {0};
    for (int i=0;i<n;i++) {
        hash[arr[i]] += 1;
    }

    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << num << " : " << hash[num] << endl;

    }
}