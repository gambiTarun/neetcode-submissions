class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        int mid;
        int res=lo;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(canSplit(nums, k, mid)){
                res = mid;
                std::cout << res << std::endl;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return res;
    }

    bool canSplit(vector<int> &nums, int k, int target){
        int splits=1;
        int cursum=0;
        for(auto &n : nums){
            cursum+=n;
            if(cursum > target){
                splits++;
                if(splits>k)
                    return false;
                cursum = n;
            }
        }
        return true;
    }
};