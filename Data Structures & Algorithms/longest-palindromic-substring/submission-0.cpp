class Solution {
public:
    string longestPalindrome(string s) {
        int longest=0;
        string res="";
        for(int i=0;i<s.size();i++){
            // odd len
            int l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            if(r-l+1 > longest){
                longest = r-l+1;
                std::cout << l << std::endl;
                res = s.substr(l, r-l+1);
            }

            // even len
            l = i;
            r = i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            if(r-l+1 > longest){
                longest = r-l+1;
                std::cout << l << std::endl;
                res = s.substr(l, r-l+1);
            }
        }
        return res;
    }
};
