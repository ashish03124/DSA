//LOGIC
class Solution {
public:
    int child1(vector<vector<int>>& arr,int j, int n){
        int count = 0;
        for(int i=0;i<n;i++){
            count += arr[i][i];
        }
        return count;
    }
    int child2(vector<vector<int>>& arr,int i, int j, int n){
        if(i>=n || j>=n || j<0) return 0;
        if(i==n-1 && j==n-1) return 0;
        if(i==j || i>j) return 0;
        int bl = arr[i][j] + child2(arr,i+1,j-1,n);
        int bd = arr[i][j] + child2(arr,i+1,j,n);
        int br = arr[i][j] + child2(arr,i+1,j+1,n);
        return max({bl,bd,br});

    }
    int child3(vector<vector<int>>& arr,int i, int j,int n){
        if(i>=n || j>=n || j<0) return 0;
        if(i==n-1 && j==n-1) return 0;
        if(i==j || i<j) return 0;
        int ul = arr[i][j] + child3(arr,i-1,j+1,n);
        int u = arr[i][j] + child3(arr,i,j+1,n);
        int ur = arr[i][j] + child3(arr,i+1,j+1,n);
        return max({ul,u,ur});

    }
    int maxCollectedFruits(vector<vector<int>>& arr) {
        int n = arr.size();
        // vector<vector<int>> t(n,vector<int>(n,-1));
        int c1 = child1(arr,0,n);
        int c2 = child2(arr,0,n-1,n);
        int c3 = child3(arr,n-1,0,n);
        return c1+c2+c3;
    }
};