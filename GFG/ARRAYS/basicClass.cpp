//
// Created by Agaru on 9/11/2025.
//
#include <bits/stdc++.h>
using namespace std;
int main() {

    int arr[10] = {1,2,3,4,56,7,8,9,10};
    int n;
    cin >> n;
    bool flag = false;
    for (int i=0;i<10;i++) {
        if (arr[i]==n) {
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