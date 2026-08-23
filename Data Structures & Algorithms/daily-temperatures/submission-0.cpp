class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> s;
        stack<int> pos;
        s.push(1000);//sentinel
        for(int i=0;i<temperatures.size();i++){
            if(temperatures[i]<=s.top()){
                s.push(temperatures[i]);
                pos.push(i);
            }
            else{
                while(temperatures[i]>s.top()){
                    ans[pos.top()]=i-pos.top();
                    pos.pop();
                    s.pop();
                }
                s.push(temperatures[i]);
                pos.push(i);
            }
        }
        return ans;
    }
};
