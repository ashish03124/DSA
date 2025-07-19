//
// Created by Agaru on 7/20/2025.
//Unordered map stores in Unsorted order
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    for (int i=0;i<n;i++) {
        mp[arr[i]]++;
    }
    //iterate int the map
    for ( auto it : mp) {
        cout << it.first << "->" << it.second << endl;
    }
    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << num << " : " << mp[num] << endl;
    }
    return 0;
}