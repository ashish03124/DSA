//
// Created by Agaru on 1/29/2026.
//
#include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string k) {
    int i=0,j=0;
    while (i<s.size() && j<k.size()) {
        if (s[i]==k[j]) i++;
        j++;
    }
    return i==s.size();
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, k;
        cin >> s >> k;

        if (isSubsequence(s, k) || isSubsequence(k, s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
