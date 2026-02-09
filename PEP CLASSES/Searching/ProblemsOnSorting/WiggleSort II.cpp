//
// Created by Agaru on 1/28/2026.
//
#include <bits/stdc++.h>
using namespace std;
void wigglesort(vector<int> &arr) {
    int n = 6;
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    int mid = (n-1)/2;
    int end = n-1;
    for (int i=0;i<n;i++){
        if (i%2==0) {
            arr[i] = temp[mid--];
        }
        else {
            arr[i] = temp[end--];
        }
    }
}
int main() {
    vector<int> arr = {3, 5, 1, 2 , 6, 4};
    wigglesort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
}