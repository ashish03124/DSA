//
// Created by Agaru on 1/24/2026.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0};
    int n = 14;
    int j=n-1, zero=0;
            for (int i=0; i<=j; i++) {
                while (arr[i]==0 && i>zero) {
                    swap(arr[i], arr[zero++]);
                }
        }
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    }
