class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> s;
        for(int i=0; i<n; i++){
            if(asteroids[i] > 0){
                s.push(asteroids[i]);
            }
            else {
                s.push(asteroids[i]);
                while(s.size()>1){
                    int temp1 = s.top();
                    s.pop();
                    int temp2 = s.top();
                    s.pop();
                    if(temp2 < 0){
                        s.push(temp2);
                        s.push(temp1);
                        break;
                    }
                    if(abs(temp1) > temp2){
                        s.push(temp1);
                        continue;
                    }
                    else if(abs(temp1) < temp2){
                        s.push(temp2);
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        stack<int> reverse_s;
        while(!s.empty()){
            reverse_s.push(s.top());
            s.pop();
        }

        while(!reverse_s.empty()){
            ans.push_back(reverse_s.top());
            reverse_s.pop();
        }

        return ans;
    }
};