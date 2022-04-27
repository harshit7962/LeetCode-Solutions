class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        v = nums;
    }
    
    int sumRange(int left, int right) {
        int res=0;
        for(int i=left;i<=right;i++) res+=v[i];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */