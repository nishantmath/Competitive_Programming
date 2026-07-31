class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int high=matrix.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }int row=high;
        if(row<0)return false;
        low=0;
        high=matrix[row].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[row][mid]<target){
                low=mid+1;
            }else if(matrix[row][mid]>target){
                high=mid-1;
            }else if(matrix[row][mid]==target){
                return true;
            }
        }return false;
    }
};