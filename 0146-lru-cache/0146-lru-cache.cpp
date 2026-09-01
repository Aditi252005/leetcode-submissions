class LRUCache {
public:
    unordered_map<int,pair<int,int>> mp;
    int counter=0;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        counter++;
        int ans=-1;
        if(mp.find(key)!=mp.end()) ans= mp[key].first;
        if(ans!=-1) mp[key].second=counter;
        return ans;
    }
    
    void put(int key, int value) {
        counter++;
        mp[key].first=value;
        mp[key].second=counter;

        if(mp.size()>cap){
            int mini=INT_MAX;
            int k;
            for(auto it:mp){
                if(it.second.second<mini){
                    mini=it.second.second;
                    k=it.first;
                }
            }

            mp.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */