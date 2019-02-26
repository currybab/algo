class Solution {
public:
    
    void permuteHelper(vector<vector<int>>& res, vector<int>& nums, int n) {
        res.push_back(nums);
        for(int i = n; i < nums.size() - 1; i ++) {
            for(int j = i + 1; j < nums.size(); j ++) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                permuteHelper(res, nums, i + 1);
                nums[j] = nums[i];
                nums[i] = t;
            }
        }       
    };
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res = vector<vector<int>>();
        permuteHelper(res, nums, 0);
        return res;
    };
    
    
};