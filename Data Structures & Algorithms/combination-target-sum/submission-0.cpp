class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backprop(0, 0, {}, nums, target, res);
        return res;
    }

    void backprop(int s, int i, vector<int> cur, vector<int>& nums, int target, vector<vector<int>> &res){
        if(target==0){
            res.push_back(cur);
        }

        for(int n=s; n<nums.size(); n++){
            if(target-nums[n]<0)
                break;
            cur.push_back(nums[n]);
            backprop(n, i, cur, nums, target-nums[n], res);
            cur.pop_back();
        }
    }
};
