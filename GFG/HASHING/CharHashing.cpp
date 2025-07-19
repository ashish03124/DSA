//
// Created by Agaru on 7/20/2025.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    int hash[256] = {0};
    for (char ch : str) {
        hash[ch]++ ;
    }
    int n = str.size();
        for (char c : str){
            cout << c << " : " << hash[c] << endl;
        }

    return 0;
}