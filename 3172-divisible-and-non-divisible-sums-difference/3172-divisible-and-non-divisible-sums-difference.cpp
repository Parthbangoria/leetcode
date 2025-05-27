class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;
        for(int i=1; i<n+1; i++){
            if( i%m != 0){
               num1 += i;
            }
            else {
                num2 += i;            }
        }
        int diff = num1 - num2;
        return diff;
    }
};