class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int l=0;
        int r=0;
        unordered_map<char,int> count;
        while(r<s.size()){
            count[s[r]]++;
            while(count[s[r]]>1){
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
