class Solution {
public:
    int countSubarray(vector<int>& arr) {
        unordered_map<int, int> map;
        map[0] =1;
        int result = 0;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                count += 1;
            }else{
                count += -1;
            }
            if(map.find(count)!=map.end()){
                result += map[count];
            }
            map[count]++;

        }
        return result;
    }
};
