class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int l=0;
        int r=0;
        unordered_set<char> cset;
        while(r<s.size()){
            while(cset.count(s[r])){
                cset.erase(s[l]);
                l++;
            }
            cset.insert(s[r]);
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
