class Robot {
public:
    int n,m;
    int x,y;
    int dy,dx;
    Robot(int width, int height) {
        n=width;
        m=height;
        x=0;
        y=0;
        dx=1;
        dy=0;
    }
    
    void step(int num) {
        int cycle = 2 * (n + m) - 4;
        if (cycle > 0) {
            num %= cycle;
            if (num == 0 && (x == 0 && y == 0) && dx == 1 && dy == 0) {
                dx = 0;
                dy = -1; 
                return;
            }
        }
        int nx=x,ny=y;
        while(num){
            if(dx==1){
                if(x+num<=n-1){
                    nx=x+num;
                    num=0;
                    break;
                }else{ //out of bounds
                    nx=n-1;
                    num-=nx-x;
                    dy=1;
                    dx=0;
                }
            }else if(dy==1){
                if(y+num<=m-1){
                   ny=y+num;
                   num=0;
                   break; 
                } 
                else{
                    ny=m-1;
                    num-=ny-y;
                    dy=0;
                    dx=-1;
                }
            }
            else if(dx==-1){
                if(x-num>=0){
                    nx=x-num;
                    num=0;
                    break;
                }
                else{
                    nx=0;
                    num-=x-nx;
                    dy=-1;
                    dx=0;
                }
            }
            else if(dy==-1){
                if(y-num>=0){
                    ny=y-num;
                    num=0;
                    break;
                }
                else{
                    ny=0;
                    num-=y-ny;
                    dy=0;
                    dx=1;
                }
            }
            x=nx;
            y=ny;
        }
        x=nx;
        y=ny;
        
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dy==1) return "North";
        else if(dy==-1) return "South";
        else if(dx==1) return "East";
        else return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */