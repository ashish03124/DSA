#include <bits/stdc++.h>
using namespace std;

void TwoSum(vector<int>& arr, int t, int i, int j, vector<vector<int>>& result){
    while(i < j){
        if(arr[i] + arr[j] > t){
            j--;
        }
        else if(arr[i] + arr[j] < t){
            i++;
        }
        else{
            while(i < j && arr[i] == arr[i+1]) i++;
            while(i < j && arr[j] == arr[j-1]) j--;
            result.push_back({-t, arr[i], arr[j]});
            i++;
            j--;
        }
    }
}

vector<vector<int>> ThreeSum(vector<int> arr){
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]){
            continue;
        }
        int n1 = arr[i];
        int target = -n1;
        TwoSum(arr, target, i+1, n-1, result);
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> result = ThreeSum(arr);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}