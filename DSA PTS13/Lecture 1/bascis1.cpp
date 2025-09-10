//
// Created by Agaru on 9/10/2025.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,2,3,5,-1,-4};
    int n = arr.size();
    int maxi  = arr[0];
    int curr = arr[0];
    for (int i=1;i<n;i++)
        {
        curr = max(arr[i], curr+arr[i]);
        maxi = max(curr, maxi);
    }
    cout << maxi << endl;
    return 0;
}