class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();

        int i=0;
        while(i<m){
            if(flowerbed[i]==1){
                int pv= i==0?i:i-1;
                int nx= i==m-1?i:i+1;

                flowerbed[pv]=-1;
                flowerbed[nx]=-1;
                
            }
            i++;
        }
        for(int i=0;i<m;i++){
            if(flowerbed[i]==0) {
                n--;
                int pv= i==0?i:i-1;
                int nx= i==m-1?i:i+1;

                flowerbed[pv]=-1;
                flowerbed[nx]=-1;
            }
        }

        return n<=0;

    }
};