class Solution {
public:
    int findSubarray(vector<int> &arr) {
        // code here.
        unordered_map<int,int> st;
        int sum = 0;
        int cnt=0;
        st[0]=1;
        for(int c : arr){
            sum += c;
            cnt += st[sum];
            st[sum]++;
        }
        return cnt;
    }
};