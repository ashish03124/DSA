//
// Created by Agaru on 7/20/2025.
//map stores in sorted order
#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;

    map<char, int> mp;
    for (char c : str) {
        mp[c]++;
    }
    //iterate int the map
    for ( auto it : mp) {
        cout << it.first << "->" << it.second << endl;
    }
    for (char c : str){
        cout << c << " : " << mp[c] << endl;
    }
    return 0;
}