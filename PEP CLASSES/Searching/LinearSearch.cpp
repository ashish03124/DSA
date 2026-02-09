//
// Created by Agaru on 1/27/2026.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool flag = false;
    for (int x : arr) {
        if (x==10) {
            flag = true;
        }
    }
    if (flag) {
        cout << "found" << endl;
    }
    else {
        cout << "not found" << endl;
    }


    return 0;
}