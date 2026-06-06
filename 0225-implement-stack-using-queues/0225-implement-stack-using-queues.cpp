class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        // queue<int> q1,q2;
    }
    
    void push(int x) {
        if(q1.size()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
    }
    
    int pop() {
        int p=q1.front();
        q1.pop();

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }

        return p; 
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
       if(q1.empty()) return true;
       return false; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */