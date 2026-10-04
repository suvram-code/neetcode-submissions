class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> p(cmp);
        for(vector<int> c: points){
            if(p.size()==k){
                vector<int> t=p.top();
                if((c[0]*c[0] + c[1]*c[1]) < (t[0]*t[0] + t[1]*t[1]) ){
                    p.pop();
                    p.push(c);
                }
            }else p.push(c);
        }

        while(!p.empty()){
            v.push_back(p.top());
            p.pop();
        }

        return v;

    }
};
