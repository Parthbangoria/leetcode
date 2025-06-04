class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        unordered_set<int> s;
        unordered_map<int,int> m; 
        for(int i=0; i<n; i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 0;
            }
            m[nums[i]]++;
            if(m[nums[i]] > n/3 ){
                s.insert(nums[i]);
                m[nums[i]] = 0;
            }
        }
        vector<int> ans(s.begin(), s.end());

        return ans;
    }
};