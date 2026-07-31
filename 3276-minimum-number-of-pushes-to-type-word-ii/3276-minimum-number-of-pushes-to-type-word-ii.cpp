class Solution {
public:
    int minimumPushes(string word) {
        vector<int>m(26, 0);
        for(char a:word)m[a-'a']+=1;
        sort(m.begin(), m.end(), greater<int>());
        int count=0;
        int mul=0;
        for(int i=0;i<26;i++){
            if(i%8==0)mul++;
            count+=(mul*m[i]);
        }
        return count;
    }
};