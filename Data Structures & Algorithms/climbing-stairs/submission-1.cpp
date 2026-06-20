class Solution {
public:
    int climbStairs(int n) {
        int n_1=1;
        int n_2=1;
        for(int i=0;i<n-1;i++){
            int temp = n_1;
            n_1 = n_1 + n_2;
            n_2 = temp;
        }
        return n_1;
    }
};
