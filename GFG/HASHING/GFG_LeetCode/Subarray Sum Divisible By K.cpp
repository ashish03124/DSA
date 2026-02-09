class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int sum = 0;
        int result=0;
        for(int c : nums){
            sum += c;
            int m = sum%k;
            result += map[m];
            map[m]++;
        }
        return result;
    }
};