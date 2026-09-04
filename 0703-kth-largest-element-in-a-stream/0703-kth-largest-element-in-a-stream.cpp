class KthLargest {
public:
    priority_queue<int> a;
    priority_queue<int,vector<int>,greater<>> b;
    int k;
    KthLargest(int l, vector<int>& nums) {
        int n=nums.size();
        k=l;
        if(k==1) {for(int it:nums) a.push(it);}
        else{
            for(int i=0;i<min(n,k-1);i++) b.push(nums[i]);
            for(int i=k-1;i<n;i++){
                if(b.top()<=nums[i]) {a.push(b.top());b.pop();b.push(nums[i]);}
            }
        }
    }
    
    int add(int val) {
        if(b.size() && b.top()<=val) {a.push(b.top());b.pop();b.push(val);}
        else a.push(val);
        return a.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */