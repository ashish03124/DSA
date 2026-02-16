//
// Created by Agaru on 2/16/2026.
//
#include <bits/stdc++.h>
using namespace std;
bool GoldRush(int n, int m) {
    if (n==m) return true;
    if (n%3!=0 || n<m) {
        return false;
    }
    return GoldRush(n/3, m) || GoldRush((n/3)*2, m);
}
int main() {
    int a;
    cin >> a;
    while (a--) {
        int n,m;
      cin >> n >> m;
        if (GoldRush(n,m)) {
            cout << "Yes\n";
        }else {
            cout << "No\n";
        }
    }
}