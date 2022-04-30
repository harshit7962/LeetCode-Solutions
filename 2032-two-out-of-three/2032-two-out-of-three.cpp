class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>ans;
        map<int,int>mp;
        set<int>s1(nums1.begin(),nums1.end()); 
        set<int>s2(nums2.begin(),nums2.end());
        set<int>s3(nums3.begin(),nums3.end());
        for(int i : s1){
                mp[i]++;
        }
        for(int i : s2){
                mp[i]++;
        }
        for(int i : s3){
                mp[i]++;
        }
        for(auto it:mp){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};