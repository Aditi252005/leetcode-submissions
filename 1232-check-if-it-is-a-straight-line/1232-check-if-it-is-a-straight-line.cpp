class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        int n=coord.size();
        const int inf=1e5;
        sort(coord.begin(),coord.end());

        float m= (coord[1][0]-coord[0][0])==0?inf:(float)(coord[1][1]-coord[0][1])/(coord[1][0]-coord[0][0]);

        for(int i=1;i<n-1;i++){
            float m2=(coord[i+1][0]-coord[i][0])==0?inf:(float)(coord[i+1][1]-coord[i][1])/(coord[i+1][0]-coord[i][0]);

            if(m!=m2) return false;
        }
        return true;
    }
};