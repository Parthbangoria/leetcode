class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x = n;
        if(n <= 0) return false;
        while(x>2){
            if(x%2 != 0) return false;
            x/=2;
        }
        return true;
    }
};