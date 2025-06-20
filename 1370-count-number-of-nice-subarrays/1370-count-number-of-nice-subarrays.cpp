class Solution {
public:
    int helper(vector<int>& nums, int k){
        int l=0, r=0;
        int count_odds = 0;
        int count = 0;
        while(r<nums.size()){
            if(nums[r]%2 != 0){
                count_odds += 1;
            }
            while(count_odds > k){
                if(nums[l]%2 != 0){
                    count_odds -= 1;
                }
                l++;
            }
            count += (r-l) +1;
            r++;
        }
        return count;
    }



    int numberOfSubarrays(vector<int>& nums, int k) {
        int count  = helper(nums, k);
        int count_small = helper(nums, k-1);

        return count - count_small;
    }
};