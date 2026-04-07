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
        
        while(num){
            int nx=x,ny=y;
            if(dx==1){
                nx=min(x+num,n-1);
                num=num-(nx-x);
                if(num) {dy=1;dx=0;}
            }else if(dy==1){
                ny=min(y+num,m-1);
                num=num-(ny-y);
                if(num){dy=0;dx=-1;}
            }
            else if(dx==-1){
                nx=max(x-num,0);
                num=num-(x-nx);
                if(num){dy=-1;dx=0;}
            }
            else if(dy==-1){
                ny=max(y-num,0);
                num=num-(y-ny);
                if(num){dy=0;dx=1;}
            }
            x=nx;
            y=ny;
        }
        
        
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