class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]-a[0]>b[1]-b[0];
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
       
        sort(tasks.begin(),tasks.end(),cmp);
        int mini=0;
        int cur=0;

        for(int i=0;i<n;i++){
            if(cur>=tasks[i][1]) cur-=tasks[i][0];
            else{
                int dif=tasks[i][1]-cur;
                mini+=dif;
                cur+=dif;
                cur-=tasks[i][0];
            } 
        }
        return mini;
    }
};