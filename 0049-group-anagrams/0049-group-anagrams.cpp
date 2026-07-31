class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>result;
        unordered_map<string, vector<string>>res;
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(), s.end());
            res[s].push_back(strs[i]);
        }
        for(auto &p:res){
            result.push_back(p.second);
        }return result;
    }
};