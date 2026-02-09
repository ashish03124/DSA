#include<bits/stdc++.h>
using namespace std;
vector<int> TwoSum(vector<int> arr, int target){
    int n = arr.size();
    map<int, int> mp;
    for(int i=0;i<n;i++){
        int remain = target - arr[i];
        if(mp.find(remain) != mp.end()){
            return {mp[remain], i};
        }
        mp[arr[i]] = i;
    }
    return {};
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i] ;
    }
    int target;
    cin >> target;
    vector<int> result = TwoSum(arr, target);
    cout << result[0] << " , " << result[1];

    return 0;
}