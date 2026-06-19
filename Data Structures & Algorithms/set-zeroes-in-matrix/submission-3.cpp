class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> setr(m, 0);
        vector<int> setc(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    setr[i]=1;
                    setc[j]=1;
                }
            }
        }
        vector<int> zeror(n,0);
        for(int i=0;i<m;i++){
            if(setr[i]){
                matrix[i] = zeror;
            }
            for(int j=0;j<n;j++){
                if(setc[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
