class Solution {
public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> hm;
        int sum = 0, count = 0;
        hm[0] = 1;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            int rem = sum - k;
            if (hm.find(rem) != hm.end()) {
                count += hm[rem];
            }
            hm[sum]++;
        }
        return count;
    }
};