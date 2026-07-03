class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target, window;
        for(char c: t)
            target[c]++;

        int have = 0;
        int need = target.size();
        int l=0;
        int r=0;
        string res = "";
        int minsize = INT_MAX;
        while(r<s.size()){
            window[s[r]]++;
            if(target.count(s[r]) && window[s[r]] == target[s[r]])
                have++;
            while(have==need){
                // printf("%d, %d, %d\n", have, window[s[l]], l);
                if(r-l+1<minsize){
                    res = s.substr(l, r-l+1);
                    minsize = r-l+1;
                }
                window[s[l]]--;
                if(target.count(s[l]) && window[s[l]] < target[s[l]])
                    have--;
                l++;
            }
            r++;
        }
        return res;
    }
};
