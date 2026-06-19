class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return dfs(text1, text2, 0, 0, mp);
    }

    int dfs(string &text1, string &text2, int i, int j, auto &mp){
        if(i<=text1.size() && j<=text2.size() && mp[i][j]!=-1)
            return mp[i][j];
        
        if(i==text1.size() || j==text2.size()){
            mp[i][j]=0;
            return 0;
        }
        if(text1[i]==text2[j]){
            mp[i][j] = 1+dfs(text1,text2,i+1,j+1,mp);
            return mp[i][j];
        }
        mp[i][j] = max(dfs(text1,text2,i+1,j,mp), dfs(text1, text2,i,j+1,mp));
        return mp[i][j];
    }
};
