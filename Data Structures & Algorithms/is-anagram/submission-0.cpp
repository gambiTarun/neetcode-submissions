class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int p[26]={0};
        for(auto &c: s){
            p[c - 'a']++;
        }
        for(auto &c: t){
            p[c - 'a']--;
        }
        for(int i:p){
            if(i)
                return false;
        }
        return true;
    }
};
