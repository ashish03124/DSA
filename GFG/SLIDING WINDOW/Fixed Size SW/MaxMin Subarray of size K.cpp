//
// Created by Agaru on 8/11/2025.
//
/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.



Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 */
// Two pointer : i = start of window
//               j = end of window
//               size of window = j - i + 1 = window size

#include <bits/stdc++.h>
using namespace std;
void MaxSum(int arr[] , int m, int k) {
    int i = 0;
    int j = 0;
    int sum = 0;
    int Max = INT_MIN;
    while (j<m) {
        sum += arr[j];
        if (j-i+1 < k) {
            j++;
        }
        else if (j-i+1 == k) {
            Max= max(Max, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    cout << Max << endl;
}
int main() {
    int arr[] = {1, 2 ,3 , 4 , 5, 6, 7, 8, 9, 11};
    int m = sizeof(arr)/sizeof(arr[0]);

    MaxSum(arr,m, 3);
    return 0;
}