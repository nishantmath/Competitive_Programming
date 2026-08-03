class Solution {
public:
int dp[500][500][2];
int solve(int p, int l, int r, vector<int> &piles){
    if(l==r){
        if(p==0){
            return 1*piles[l];
        }else{
            return -1*piles[l];
        }
    }
    if(dp[l][r][p]!=INT_MIN)return dp[l][r][p];
    int m=((p==0)?1:-1);
    int left=m*piles[l]+solve(1-p, l+1, r, piles);
    int right=m*piles[r]-solve(1-p, l, r-1, piles);
    if(p==0){
        return dp[l][r][p]=max(left, right);
    }else{
        return dp[l][r][p]=min(left, right);
    }
}
    bool stoneGame(vector<int>& piles) {
        for(int i=0;i<500;i++){
            for(int j=0;j<500;j++){
                dp[i][j][0]=dp[i][j][1]=INT_MIN;
            }
        }return solve(0, 0, piles.size()-1, piles);
    }
};