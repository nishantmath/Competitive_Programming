class Solution {
public:
vector<vector<int>>vs;
  void solve(int idx, vector<int> temp, vector<int> &candi, int target){
      int n=candi.size();
      if(idx>=n){
        if(target==0)vs.push_back(temp);return;
        }
      if(candi[idx]<=target){
          temp.push_back(candi[idx]);
          solve(idx, temp, candi, target-candi[idx]);
          temp.pop_back();
      }solve(idx+1, temp, candi, target);
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(0, temp, candidates, target);
        return vs;
    }
};