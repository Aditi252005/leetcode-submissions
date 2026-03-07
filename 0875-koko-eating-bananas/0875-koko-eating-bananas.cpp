class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int lo=1;
        int hi=piles[n-1];
        int ans=piles[n-1];
        while(lo<hi){
            int mid= lo+(hi-lo)/2;
            int k=0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid==0) k=k+piles[i]/mid;
                else k=k+ (piles[i]/mid) +1;
            }
            if(k<=h){   //satisfy, mid dec
                hi=mid; 
                ans=min(ans,mid);
            }
            else lo=mid+1;

        }
        return ans;
    }
};