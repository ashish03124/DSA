//
// Created by Agaru on 1/22/2026.
//
#include<bits/stdc++.h>
using namespace std;
vector<int> Question_9(vector<vector<int>> &arr) {
    vector<int> result9;
    int n = 4;
    for (int col=0;col<n;col++) {
        int i=col, j = 0;
        while (i>=0 && j<n) {
            result9.push_back(arr[i][j]);
            i--,j++;
        }
    }
    for (int row=1;row<n;row++) {
        int i = n-1, j = row;
        while (i>=0 && j < n) {
            result9.push_back(arr[i][j]);
            i--,j++;
        }
    }
    return result9;
}

// vector<int> Question_10(vector<vector<int>> &arr) {
//     vector<int> result10;
//     int n = 4;
//     for (int col = n-1; col>=0;col--) {
//         int i=0, j=col;
//         while(i>=0 && j>=0) {
//             result10.push_back(arr[i][j]);
//             i--,j--;
//         }
//     }
//     for (int row=n-1;row>=0;row--) {
//         int i=row, j=n-1;
//         while (i>=0 && j>=0) {
//             result10.push_back(arr[i][j]);
//             i--,j--;
//         }
//     }
//     return result10;
// }
vector<int> Question_11(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<int> result11;
    for (int col = 0; col < n+m-1; col++) {
        if (col%2==0) {
            int i=min(col, n-1);
            int j = col - i;
            while (i>=0 && j<m) {
                result11.push_back(arr[i][j]);
                i--;
                j++;
            }
        }
        else {
            int j = min(col , m-1);
            int i = col - j;
            while (j>=0 && i<n) {
                result11.push_back(arr[i][j]);
                i++;
                j--;
            }
        }
    }
    return result11;
}

vector<int> Question_12(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<int> result11;
    for (int col = 0; col < n+m-1; col++) {
        if (col%2==0) {
            int j = min(col , m-1);
            int i = col - j;
            while (j>=0 && i<n) {
                result11.push_back(arr[i][j]);
                i++;
                j--;

            }
        }
        else {
            int i=min(col, n-1);
            int j = col - i;
            while (i>=0 && j<m) {
                result11.push_back(arr[i][j]);
                i--;
                j++;
            }
        }
    }
    return result11;
}
int main() {
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    vector<int> ans = Question_9(arr);
    for (int j : ans)
        cout << j << " ";
    cout << "\n" << endl;

    // vector<int> anss = Question_10(arr);
    // for (int j : anss)
    //     cout << j << " ";
    // cout << "\n" << endl;

    vector<int> anss = Question_11(arr);
    for (int j : anss)
        cout << j << " ";
    cout << "\n" << endl;

    vector<int> ansss = Question_12(arr);
    for (int j : ansss)
        cout << j << " ";
    cout << "\n" << endl;
    return 0;
}