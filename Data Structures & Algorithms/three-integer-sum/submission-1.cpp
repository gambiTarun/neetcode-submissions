class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-1;i++){
            if(i-1>=0 && nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]<-nums[i])
                    l++;
                else if(nums[l]+nums[r]>-nums[i])
                    r--;
                else{
                    while(l+1<nums.size() && nums[l]==nums[l+1])
                        l++;
                    while(r-1>=0 && nums[r]==nums[r-1])
                        r--;
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
