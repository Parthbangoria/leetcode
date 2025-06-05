class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int childs = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0;
        int r = 0;

        while(l<g.size() && r<s.size()){
            if(g[l] <= s[r]){
                childs ++;
                l++;
                r++;
            }
            else{
                r++;
            } 
        }

        return childs;
    }
};