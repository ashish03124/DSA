//
// Created by Agaru on 1/28/2026.
//
/*Given an unsorted array nums, reorder it in-place such that
nums[0] <= nums[1] >= nums[2] <= nums[3]....
There may have multiple answers for a question, you only need to consider one of the possibilities.

 */
#include <bits/stdc++.h>
using namespace std;
void wigglesort(int arr[]) {
    int n = 6;
    for (int i=1;i<n;i++) {
        if ((i%2==1 && arr[i] < arr[i-1]) ||
            (i%2==0 && arr[i] > arr[i-1]))
            swap(arr[i], arr[i-1]);
    }
}
int main() {
    int arr[] = {3, 5, 1, 2 , 6, 4};
    wigglesort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
}