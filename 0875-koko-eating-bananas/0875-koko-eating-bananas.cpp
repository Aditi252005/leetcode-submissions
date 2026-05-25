class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int lo=1;
        int hi=piles[n-1];

        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int a=0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid==0) a=a+piles[i]/mid;
                else a=a+piles[i]/mid +1;                
                if(a>h) break;
            }
            if(a<=h) hi=mid;
            else lo=mid+1;
        }

        return lo;
    }
};