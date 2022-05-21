class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<vector<int>> res(2, vector<int>());
        
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]<nums2[j]) {
                res[0].push_back(nums1[i]);
                while(i+1<nums1.size() && nums1[i]==nums1[i+1]) i++;
                i++;
            }
            else if(nums1[i]>nums2[j]) {
                res[1].push_back(nums2[j]);
                while(j+1<nums2.size() && nums2[j]==nums2[j+1]) j++;
                j++;
            }
            else {
                while(i+1<nums1.size() && nums1[i]==nums1[i+1]) i++;
                while(j+1<nums2.size() && nums2[j]==nums2[j+1]) j++;
                i++;
                j++;
            }
        }
        
        while(i<nums1.size()) {
            if(i==0 || nums1[i]!=nums1[i-1]) res[0].push_back(nums1[i++]);
            else i++;
        }
        
        while(j<nums2.size()) {
            if(j==0 || nums2[j]!=nums2[j-1]) res[1].push_back(nums2[j++]);
            else j++;
        }
        return res;
    }
};