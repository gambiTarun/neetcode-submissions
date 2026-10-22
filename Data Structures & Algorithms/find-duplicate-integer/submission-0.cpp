class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p[10001] = {};
        for(auto& n: nums)
            p[n]++;
        
        for(int i=1;i<=10000;i++)
            if(p[i]>1)
                return i;
        return -1;
    }
};
