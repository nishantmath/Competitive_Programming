class Solution {
public:
    int solve(bool turn, int l, int r, vector<int> &nums) {
        if(l==r){
            if(turn)return 1*nums[l];
            else return -1*nums[l];
        }        
        if(turn){
            int leftChoice=nums[l]+solve(!turn, l+1, r, nums);
            int rightChoice=nums[r]+solve(!turn, l, r-1, nums);
            return max(leftChoice, rightChoice);
        }else{
            int leftChoice=-nums[l]+solve(!turn, l+1, r, nums);
            int rightChoice=-nums[r]+solve(!turn, l, r-1, nums);
            return min(leftChoice, rightChoice);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(true, 0, nums.size()-1, nums)>=0;
    }
};