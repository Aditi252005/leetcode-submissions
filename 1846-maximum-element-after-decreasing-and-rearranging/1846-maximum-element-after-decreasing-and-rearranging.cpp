class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int op=0;
        if(arr[0]!=1) {arr[0]=1;op++;}

        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]>1) {
                op++;
                arr[i]=arr[i-1]+1;
            }
        }
        return arr[n-1];
    }
};