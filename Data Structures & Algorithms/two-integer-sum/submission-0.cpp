class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        for(int i=0;i<nums.size();i++){
            if(idx.count(target-nums[i])){
                return {idx[target-nums[i]],i};
            }
            idx[nums[i]]=i;
        }
        return {};
    }
};
