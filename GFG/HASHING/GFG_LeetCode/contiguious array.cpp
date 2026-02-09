class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        map[0] = -1;
        int result = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count += 1;
            }else{
                count += -1;
            }
            if(map.find(count)!=map.end()){
                result = max(result, i-map[count]);
            }else{
                map[count]=i;
            }
        }
        return result;
    }
};