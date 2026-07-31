class Solution {
public:
vector<vector<string>>Queens;
bool isSafe(int i, int j, int n, vector<string>Q){
    int a = i - 1, b = j - 1;   
    while (a >= 0 && b >= 0) {
        if (Q[a][b] == 'Q') return false;
        a--;b--;
    }
    a = i - 1;b = j + 1;
    while (a >= 0 && b < n) {
        if (Q[a][b] == 'Q') return false;
        a--;b++;
    }
    a = i - 1;
    while (a >= 0) {
        if (Q[a][j] == 'Q') return false;
        a--;
    }
    return true;
}
void solve(int row, int n, vector<string> &Q){
    if(row>=n)Queens.push_back(Q);
    string s(n, '.');
    for(int j=0; j<n; j++){
        if(row==0 || isSafe(row, j, n, Q)){
            s[j]='Q';
            Q.push_back(s);
            solve(row+1, n, Q);
            Q.pop_back();
            s[j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp;
        solve(0, n, temp);
        return Queens;
    }
};