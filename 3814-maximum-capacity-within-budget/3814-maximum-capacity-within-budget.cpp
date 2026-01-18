class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size();
        vector<pair<int,int>> v;
        vector<int> best(n);
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(costs[i]<budget) ans=max(ans,capacity[i]);
            v.push_back({costs[i],capacity[i]});
        }
       
        sort(v.begin(),v.end()); 
        best[0]=v[0].second;
        for(int i=1;i<n;i++) best[i]=max(best[i-1],v[i].second);

        int j=0;
       
        while(j<n){
            if(v[j].first<budget){
                ans=max(ans,v[j].second);
                int l=0;
                int r=j-1;
                while(l<=r){
                    int mid=l+(r-l)/2;
                    if(v[j].first+v[mid].first<budget){
                        ans=max(ans,v[j].second+best[mid]);
                        l=mid+1;
                    }else r=mid-1;
                }
            }  
            j++;
        }
        
        

        return ans;
    }
};