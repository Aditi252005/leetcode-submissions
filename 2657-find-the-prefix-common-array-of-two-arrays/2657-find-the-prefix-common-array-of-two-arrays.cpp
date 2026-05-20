class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n=A.size();

        vector<int> C(n,0);
        set<int> sta,stb;
        if(A[0]==B[0]) C[0]=1;
        sta.insert(A[0]);
        stb.insert(B[0]);

        for(int i=1;i<n;i++){
            sta.insert(A[i]);
            stb.insert(B[i]);  
            C[i]=C[i-1];
            if(A[i]==B[i]) C[i]++;
            else{
                if(sta.find(B[i])!=sta.end()) C[i]++;
                if(stb.find(A[i])!=stb.end()) C[i]++; 
            }
        }
        return C;
    }
};