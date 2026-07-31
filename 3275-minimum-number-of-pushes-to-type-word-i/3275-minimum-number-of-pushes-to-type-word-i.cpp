class Solution {
public:
    int minimumPushes(string word) {
       int n=word.size();
       int i=1;
       int sum=0;
       while(n>=8){
        sum+=8*i;
        i++;
        n-=8;
       }
       sum+=n*i;
       return sum;
    }
};