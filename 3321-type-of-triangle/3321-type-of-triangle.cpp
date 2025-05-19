class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        int max_side = 0;
        int other_sides = 0;

        for(int i=0; i<nums.size(); i++){
            max_side = max(max_side, nums[i]);
            other_sides += nums[i];
        }

        other_sides -= max_side;

        if(nums.size()>3 || nums.size()<3  || other_sides <= max_side){
            return "none";
        }

        if(nums[0] == nums[1] && nums[0] == nums[2]){
           return "equilateral";
        }
        else if(nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2]){
            return "isosceles";
        }
        else {
            return "scalene";
        }
        
    }
};