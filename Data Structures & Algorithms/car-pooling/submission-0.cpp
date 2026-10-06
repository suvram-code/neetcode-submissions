class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        auto pickup=[&trips](vector<int> a, vector<int> b){
            return a[1] > b[1];
        };
         auto drop=[&trips](vector<int> a, vector<int> b){
            return a[2] > b[2];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(pickup)> p(pickup);
        priority_queue<vector<int>, vector<vector<int>>, decltype(drop)> d(drop);
        for( vector<int> v : trips){
            p.push(v);
            d.push(v);
        }
        int n=0;
        n+=p.top()[0];
        p.pop();

        while(!p.empty()){
            if(n>capacity) return false;
            int np=p.top()[1];
            while(!d.empty()){
                if(np<d.top()[2]) break;
                n-=d.top()[0];
                d.pop();
            }
            n+=p.top()[0];
            if(n>capacity) return false;
            p.pop();

        }
        return true;
    }
};