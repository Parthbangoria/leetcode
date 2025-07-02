class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water=0;
        int lp=0;
        int rp = height.size()-1;
        while(lp<rp){
            int  h = min(height[lp],height[rp]);
            int w = rp-lp;
            max_water = max(max_water,(w*h));
            height[lp]<height[rp]?lp++:rp--;
        }
        return max_water;
    }
};