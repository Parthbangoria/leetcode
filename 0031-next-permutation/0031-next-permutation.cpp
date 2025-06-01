class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size(); 
       int pivot_index = -1;
        for(int i = n-2 ; i >= 0 ; i--) {
           if(nums[i]<nums[i+1]){
            pivot_index = i;
            break;
           }
       }
       if(pivot_index == -1){
        reverse(nums.begin(),nums.end());
        return ;
       }
    //    int next_min_index = n - 1;
       for(int i = n-1; i >= pivot_index; i--){
           if(nums[i]>nums[pivot_index] ){
            swap(nums[pivot_index],nums[i]);
            break;
           }
       } 
        int i = pivot_index + 1;
        int j = n - 1;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};