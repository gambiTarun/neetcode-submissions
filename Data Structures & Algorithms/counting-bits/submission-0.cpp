class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        int i=1;
        while(i<=n){
            res[i] = (i&1) + res[i>>1];
            i++;
        }
        return res;
    }
};
