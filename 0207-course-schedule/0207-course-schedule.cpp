class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n=pre.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[pre[i][0]].push_back(pre[i][1]);
        }
        

        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(pre[i][1]);
            set<int> vis;
           
            while(!q.empty()){
                int p=q.front();
                q.pop();
                if(vis.find(p)!=vis.end()) continue;
                vis.insert(p);
                for(auto it:mp[p]) {
                    if(it==pre[i][0])return false;
                    q.push(it);
                }
                
            }
        }
        return true;
    }
};