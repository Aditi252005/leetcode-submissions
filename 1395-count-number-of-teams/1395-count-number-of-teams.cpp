class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count=0;
      
        int n=rating.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(rating[i]<rating[j]){
                    for(int k=j+1;k<n;k++){
                        if(rating[k]>rating[j]) count++;
                    }
                }
                else if(rating[i]>rating[j]){
                    for(int k=j+1;k<n;k++){
                        if(rating[j]>rating[k]) count++;
                    }
                }
            }
        }
      return count;
    }
};