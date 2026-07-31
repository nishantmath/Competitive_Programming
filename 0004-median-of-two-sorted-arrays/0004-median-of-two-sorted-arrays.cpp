class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged;
        int i=0;
        int j=0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j])
            merged.push_back(nums1[i++]);
        else
            merged.push_back(nums2[j++]);
        }
        
        while (i < nums1.size())
            merged.push_back(nums1[i++]);

        while (j < nums2.size())
            merged.push_back(nums2[j++]);
            double med=0;
        int m=merged.size();
        cout<<m<<endl;
        for(int k:merged)
        cout<<k;
        if((m&1)==1){
            med=merged[m/2];
        }else{
            med=(double)(merged[(m/2)-1]+merged[m/2])/2;
        }
        
        return med;
    }
};