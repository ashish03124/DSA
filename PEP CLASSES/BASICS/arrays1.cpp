// Created by Agaru on 1/22/2026.
/*
 *print elements of the metrics
 *print n-1 col to 1 col row wise
 *print zigzag elements of metrics
 *print col 1 to col n-1 top-dow
 *print col 1 to col n-1 bottom-up
 *print col 1 to col n-1 zigzag
 *print elements of the metrics from arr[0][n-1] to arr[n-1][0]  normally sun is right - down
 *print elements of the metrics from arr[0][n-1] to arr[n-1][0]  zigzag
 *print elements of the metrics from arr[0][n-1] to arr[n-1][0]  normally sun is left - up
 *print elements of the metrics from arr[n-1][0] to arr[0][n-1]  normally sun is left - down
 *spiral traversal in metrics
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> Question_1(vector<vector<int>> &arr) {
    vector<int> result1;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++){
            result1.push_back(arr[i][j]);
        }
    }
    return result1;
}
vector<int> Question_2(vector<vector<int>> &arr) {
    vector<int> result2;
    for(int i=0;i<4;i++){
        for(int j=3;j>=0;j--){
            result2.push_back(arr[i][j]);
        }
    }
    return result2;
}

vector<int> Question_3(vector<vector<int>> &arr) {
    vector<int> result3;
    for(int i=0;i<4;i++){
        if(i%2==0)
            for(int j=0;j<4;j++) result3.push_back(arr[i][j]);
        else
            for(int j=3;j>=0;j--) result3.push_back(arr[i][j]);
    }
    return result3;
}
vector<int> Question_4(vector<vector<int>> &arr) {
    vector<int> result4;
    for (int j=0;j<4;j++) {
        for (int i=0;i<4;i++) {
        result4.push_back(arr[i][j]);
        }
    }
    return result4;
}

vector<int> Question_5(vector<vector<int>> &arr) {
    vector<int> result5;
    for (int j=0;j<4;j++) {
        for (int i=3;i>=0;i--) {
            result5.push_back(arr[i][j]);
        }
    }
    return result5;
}

vector<int> Question_6(vector<vector<int>> &arr) {
    vector<int> result6;
    for (int j=0;j<4;j++) {
        if (j%2==0)
            for (int i=0;i<4;i++) result6.push_back(arr[i][j]);
        else
            for (int i=3;i>=0;i--) result6.push_back(arr[i][j]);

    }
    return result6;
}
vector<int> Question_7(vector<vector<int>> &arr) {
    vector<int> result7;
    int n = 4;
    for(int col = n-1; col >= 0; col--) {
        int i = 0, j = col;
        while(i < n && j < n) {
            result7.push_back(arr[i][j]);
            i++; j++;
        }
    }
    for(int row = 1; row < n; row++) {
        int i = row, j = 0;
        while(i < n && j < n) {
            result7.push_back(arr[i][j]);
            i++; j++;
        }
    }
    return result7;
}
vector<int> Question_8(vector<vector<int>> &arr) {
    vector<int> result8;
    int n = 4;
    for(int col = 0; col < 4; col++) {
        int i = 0, j = col;
        while(i < n && j >= 0) {
            result8.push_back(arr[i][j]);
            i++; j--;
        }
    }
    for(int row = 1; row < n; row++) {
        int i = row, j = n-1;
        while(i < n && j >= 0) {
            result8.push_back(arr[i][j]);
            i++; j--;
        }
    }
    return result8;
}
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
        while (i>=0 && j<n) {
            result9.push_back(arr[i][j]);
            i--,j++;
        }
    }
    return result9;
}

vector<int> Question_10(vector<vector<int>> &arr) {
    vector<int> result10;
    int n = 4;
    for (int col = n-1; col>=0;col--) {
        int i=0, j=col;
        while(i<n && j>=0) {
            result10.push_back(arr[i][j]);
            i--,j--;
        }
    }
    for (int row=1;row<n;row++) {
        int i=row, j=n-1;
        while (i<n && j>=0) {
            result10.push_back(arr[i][j]);
            i--,j--;
        }
    }
    return result10;
}
int main() {
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    vector<int> ans = Question_1(arr);
    for(int x : ans)
        cout << x << " ";
    cout << "\n" << endl;

    vector<int> anss = Question_2(arr);
    for (int c : anss)
        cout << c << " ";
    cout << "\n" << endl;

    vector<int> ansss = Question_3(arr);
    for (int j : ansss)
        cout << j << " ";
    cout << "\n" << endl;

    vector<int> anssss = Question_4(arr);
    for (int j : anssss)
        cout << j << " ";
    cout << "\n" << endl;

    vector<int> ansssss = Question_5(arr);
    for (int j : ansssss)
        cout << j << " ";
    cout << "\n" << endl;

    vector<int> anssssss = Question_6(arr);
    for (int j : anssssss)
        cout << j << " ";
    cout << "\n" << endl;

    vector<int> ansssssss = Question_7(arr);
    for (int j : ansssssss)
        cout << j << " ";
    cout << "\n" << endl;

    vector<int> anssssssss = Question_8(arr);
    for (int j : anssssssss)
        cout << j << " ";
    cout << "\n" << endl;

    vector<int> ansssssssss = Question_9(arr);
    for (int j : ansssssssss)
        cout << j << " ";
    cout << "\n" << endl;
    return 0;

    vector<int> anssssssssss = Question_10(arr);
    for (int j : anssssssssss)
        cout << j << " ";
    cout << "\n" << endl;
    return 0;


}