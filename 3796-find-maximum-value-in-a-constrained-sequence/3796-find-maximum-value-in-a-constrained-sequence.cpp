class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> a(n,INT_MAX);
        a[0]=0;
       
        for(auto it:restrictions){
            int idx=it[0];
            int maxv=it[1];
            a[idx]=maxv;
        }

        for(int i=1;i<n;i++){
            a[i]=min(a[i],diff[i-1]+a[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            a[i]=min(a[i],diff[i]+a[i+1]);
        }

        //tle
        // queue<pair<int,int>> q;
        // q.push({0,0});
        // for(auto it:restrictions){
        //     int idx=it[0];
        //     int maxv=it[1];
        //     q.push({idx,maxv});
        // }

        // while(!q.empty()){
        //     auto it=q.front();
        //     q.pop();
        //     int idx=it.first;//1
        //     int maxv=it.second;//15
        //     a[idx]=min(a[idx],maxv);
        //     int i=idx-1;//0
        //     int j=idx+1;//2
        //     while(i>=0){
        //         a[i]=min(a[i],diff[i]+a[i+1]);
        //         i--;
        //     }
        //     while(j<n){
        //        a[j]=min(a[j],diff[j-1]+a[j-1]); 
        //        j++;
        //     }    
        // }

        int maxv=0;
        for(int i=0;i<n;i++){
            //cout<<a[i];
            maxv=max(maxv,a[i]);
        }
        return maxv;
    }
};