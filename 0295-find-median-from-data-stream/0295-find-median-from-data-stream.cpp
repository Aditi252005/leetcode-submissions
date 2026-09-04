class MedianFinder {
public:
    priority_queue<int> a;
    priority_queue<int,vector<int>,greater<>> b;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!a.size() || a.top()>=num) a.push(num);
        else b.push(num);

        if(a.size()>b.size()+1) {
            b.push(a.top());
            a.pop();
        }
        if(b.size()>a.size()+1){
            a.push(b.top());
            b.pop();
        }
    }
    
    double findMedian() {
        if(a.size()==b.size()) return (double) (a.top()+b.top())/2.0;
        if(a.size()==b.size()+1) return (double)a.top();
        else return (double) b.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */