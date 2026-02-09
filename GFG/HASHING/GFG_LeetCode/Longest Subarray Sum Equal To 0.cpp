class Solution {
public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int, int> map;
        int sum = 0;
        int result = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum==0){
                result = i+1;
            }
            if(map.find(sum)!=map.end()){
                result = max(result, i-map[sum]);
            }else{
                map[sum]=i;
            }
        }
        return result;
    }
};

