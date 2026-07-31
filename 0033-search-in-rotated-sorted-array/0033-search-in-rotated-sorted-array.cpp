class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            //left half is sorted
            if(nums[start]<=nums[mid]){
                //target is in the left half
                if(target>=nums[start] && target<nums[mid]){
                    end=mid-1;
                //target is in right half
                }else{
                    start=mid+1;
                }
            }
            //right half is sorted
            else{
                //target is in right half
                if(target>nums[mid] && target<=nums[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};