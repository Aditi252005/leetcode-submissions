class Solution {
public:
    bool f(int i,vector<int>&arr,vector<int>& vis){
        int n=arr.size();
        if(i<0 || i>n-1) return false;
        if(arr[i]==0) return true;

        if(vis[i]) return false;
        vis[i]=1;

        bool op1=f(i-arr[i],arr,vis);
        bool op2=f(i+arr[i],arr,vis);
        return op1||op2;        
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n,0);

        return f(start,arr,vis);
    }
};