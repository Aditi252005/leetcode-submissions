class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obst) {
        int n=commands.size();
        int m=obst.size();

        set<pair<int,int>> st;
        for(auto o:obst) st.insert({o[0],o[1]});

        int ans=0;
        int dy=1,dx=0;
        int x=0,y=0;
        int k=0;
        for(auto c:commands){
            if(c>=1 && c<=9){
                while(c--){
                    int nx=x+dx;
                    int ny=y+dy;
                    if(st.find({nx,ny})!=st.end()) break;
                    x=nx;
                    y=ny;
                }
                
            }else if(c==-1){
                if(dy==1) {dx=1;dy=0;}
                else if(dy==-1) {dx=-1;dy=0;}
                else if(dx==1) {dy=-1;dx=0;}
                else if(dx==-1) {dy=1;dx=0;}
            }else if(c==-2){
                if(dy==1) {dx=-1;dy=0;}
                else if(dy==-1) {dx=1;dy=0;}
                else if(dx==1) {dy=1;dx=0;}
                else if(dx==-1) {dy=-1;dx=0;}
            }
            
            ans=max(ans, x*x+y*y);
        }
        return ans;
    }
};