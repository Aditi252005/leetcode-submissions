class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();

        int mindx=-1;
        int minc=INT_MAX;
        for(int i=0;i<n;i++){
            if(capacity[i]>=itemSize){
                if(capacity[i]<minc){
                    minc=capacity[i];
                    mindx=i;
                }
            }
        }
       
        return mindx;
    }
};