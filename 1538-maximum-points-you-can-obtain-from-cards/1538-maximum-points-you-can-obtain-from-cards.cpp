class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int max_sum = 0;
        int left_sum = 0;
        int right_sum = 0;

        for(int i=0; i<k; i++){
            left_sum += cardPoints[i];
        }
        max_sum = max(max_sum, (left_sum + right_sum));

        int l = k-1;
        int r = n-1;

        while(r>=n-k){
            left_sum -= cardPoints[l];
            right_sum += cardPoints[r];
            max_sum = max(max_sum, (left_sum + right_sum));
            l--;
            r--;
        }

        return max_sum;

        // for(int j = n-1; j>=n-k; j--){
        //     right_sum += cardPoints[j];
        //     rightSum[n-j] = right_sum; 
        // }
        
        // max_sum = max(max_sum, leftSum[k]);
        // max_sum = max(max_sum, rightSum[k]);

        // for(int x = 1; x<k; x++){
        //     max_sum = (max_sum, (leftSum[x] + rightSum[k-x]));
        // }
        
        return max_sum;
    }
};