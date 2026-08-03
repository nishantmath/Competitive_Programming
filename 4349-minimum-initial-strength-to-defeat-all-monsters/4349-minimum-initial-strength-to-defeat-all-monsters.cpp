class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        int m=boosts.size();
        vector<long long>diff(n+1, 0);
        for(int i=0; i<m;i++){
            int l=boosts[i][0], r=boosts[i][1], v=boosts[i][2];
            diff[l]+=v;
            diff[r+1]-=v;
        }
        for(int i=0; i<n;i++){
            diff[i+1]+=diff[i];
        }
        auto check=[&](long long mid)->bool{
            for(int i=0; i<n;i++){
                long long p=mid+diff[i];
                if(monsters[i]>p)return false;
                mid=max(0LL, mid-monsters[i]);
            }
            return true;
        };
        long long low=0, high=LLONG_MAX;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};