//
// Created by Agaru on 2/9/2026.
//
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for(int n : nums) total += n;
        int rem = total%p;
        if(rem == 0) return 0;
        unordered_map<int, int> map;
        map[0] = -1;
        long long sum = 0;
        int result =nums.size();
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int k = sum%p;
            int w = (k-rem+p)%p;
            if (map.count(w)) {
                result = min(result, i - map[w]);
            }
            map[k]=i;
        }
        return result==nums.size() ? -1 : result;
    }
};