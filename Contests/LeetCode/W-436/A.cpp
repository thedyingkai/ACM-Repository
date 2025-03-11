//
// Created by ASUS on 2025/2/9.
//
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int x[30][20],cnt[20],n=grid[0].size();
        memset(cnt,0,sizeof(cnt));
        vector<vector<int>> res(n, vector<int>(n));
        for(int i=n-1;i>=0;i--) for(int j=0;j<n;j++) x[n-i-1+j][cnt[n-i-1+j]++]=grid[i][j];
        for(int i=0;i<=n-1;i++) sort(x[i],x[i]+i+1,[](int x,int y){return x>y;});
        if(n!=1) for(int i=n;i<2*n-1;i++) sort(x[i],x[i]+2*n-1-i,[](int x,int y){return x<y;});
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                res[i][j]=x[n-i-1+j][--cnt[n-i-1+j]];
            }
        }
        return res;
    }
};