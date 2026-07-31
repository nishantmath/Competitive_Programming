class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> idx={-1, -1};
        auto it1=lower_bound(nums.begin(), nums.end(), target);
        if( it1==nums.end() || *it1!=target){
            return idx;
        }
        auto it2=upper_bound(nums.begin(), nums.end(), target);
        idx[0]=it1-nums.begin();
        idx[1]=it2-nums.begin()-1;
        return idx;
    }
};