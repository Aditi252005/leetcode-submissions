class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
           v.push_back({positions[i],i});
        }

        sort(v.begin(),v.end());
        stack<int> st;
          

        for(int k=0;k<n;k++){
            int i=v[k].second;
            int h2=healths[i];
            char d2=directions[i];
            if(d2=='R') st.push(i); 
            else{
                while(!st.empty() && directions[st.top()]=='R' && d2=='L'){
                    int j=st.top();
                    int h1=healths[j];
                    h2=healths[i];
                    st.pop();
                    if(h1==h2){
                        healths[j]=0;
                        healths[i]=0;
                        break;
                    }
                    else if(h1>h2) {
                        healths[j]--;
                        healths[i]=0;
                        st.push(j);
                        break;
                    }
                    else if(h1<h2){
                        healths[j]=0;
                        healths[i]--;
                    }
                }
                if(healths[i]>0) st.push(i);
            }
            
            
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
           if(healths[i]>0) ans.push_back(healths[i]);
        }
       
        return ans;

    }
};