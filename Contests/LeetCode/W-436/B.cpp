//
// Created by ASUS on 2025/2/9.
//
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int mx=0;
        for(auto x:groups) mx=max(mx,x);
        vector<int> fac[mx+1];
        for(int i=1;i<=mx;i++) for(int j=i;j<=mx;j+=i) fac[j].push_back(i);
        int pos[mx+1];
        memset(pos,-1,sizeof(pos));
        for(int i=0;i<elements.size();i++){
            int x=elements[i];
            if(x<=mx&&pos[x]<0) pos[x]=i;
        }
        vector<int> ans;
        for(int x:groups){
            int t=-1;
            for(int y:fac[x]) if(pos[y]>=0&&(t==-1||t>pos[y])) t=pos[y];
            ans.push_back(t);
        }
        return ans;
    }
};