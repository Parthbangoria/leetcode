class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int max_size = 0;
        int l = 0;
        int r = 0;
        while(r<s.size()){
            if(m.find(s[r]) != m.end() && m[s[r]] >= l){
                l = m[s[r]]+1;
            }
            m[s[r]] = r;
            max_size = max(max_size, ((r-l)+1));
            r++;
        }

        return max_size;
    }
};