class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=nums.size()-1;
            // int m=0;
            while(l<r){
                // m = l + (r-l)/2;
                if(nums[l]+nums[r] < -nums[i])
                    l++;
                else if(nums[l]+nums[r] > -nums[i])
                    r--;
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && l<nums.size()-1 && nums[l]==nums[l+1])
                        l++;
                    while(l<r && r>0 && nums[r]==nums[r-1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
