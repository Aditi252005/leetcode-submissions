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
        //     int idx=it.first;//3
        //     int maxv=it.second;//2
        //     a[idx]=maxv;
        //     int i=idx-1;//2
        //     int j=idx+1;//4
        //     while(i>=1){
        //         a[i]=min(a[i],max(abs(diff[i]-a[i+1]),diff[i]+a[i+1]));
        //         i--;
        //     }
        //     while(j<n){
        //        a[j]=min(a[j],max(abs(diff[j-1]-a[j-1]),diff[j-1]+a[j-1])); 
        //        j++;
        //     }    
        // }

        int maxv=0;
        for(int i=0;i<n;i++){
            maxv=max(maxv,a[i]);
            cout<<a[i]<<" ";
        }
        return maxv;
    }
};