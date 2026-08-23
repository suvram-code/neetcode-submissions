class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(ans.empty()) {ans.push_back(asteroids[i]);
            continue;}
            if(asteroids[i]*ans.back()>0 || (asteroids[i]*ans.back()<0 && asteroids[i]>0) )   
                      ans.push_back(asteroids[i]);
            else{
                bool alive=true;
                int s=asteroids[i];
                while(!ans.empty()){
                    if(asteroids[i]*ans.back()>0 ) break;
                    if(abs(ans.back())>abs(s)) break;
                    else if(ans.back()+s==0){
                        ans.pop_back();
                        alive=false;
                        break;
                    }else{
                        ans.pop_back();
                    }
                }
                if(ans.empty() && alive || (!ans.empty() && asteroids[i]*ans.back()>0 &&alive)) ans.push_back(s);
            } 

        }
        return ans;
    }
};