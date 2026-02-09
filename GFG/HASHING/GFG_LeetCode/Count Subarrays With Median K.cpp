class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = 0;
        while (nums[idx] != k) idx++;

        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1;

        // left side
        for (int i = idx - 1; i >= 0; i--) {
            sum += (nums[i] > k ? 1 : -1);
            mp[sum]++;
        }

        int ans = 0;
        sum = 0;

        // right side (including k)
        for (int i = idx; i < n; i++) {
            if (nums[i] != k)
                sum += (nums[i] > k ? 1 : -1);

            ans += mp[-sum] + mp[1 - sum];
        }

        return ans;
    }
};
