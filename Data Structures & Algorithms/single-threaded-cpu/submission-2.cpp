class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> v;
        
        for(int i=0;i<tasks.size();i++){
            v.push_back(tasks[i]);
            v.back().push_back(i);
        }
        vector<int> ans;

        auto cmp=[](const vector<int>& a, const vector<int>& b){
            //conditon where prioroity of a < priority of b

            if(b[0]<a[0]) return true;
            else if(b[0]==a[0]){
                if(b[1]<a[1]) return true;
                else if(b[1]==a[1]){
                    if(b[2]<a[2]) return true;
                    else return false;
                }else return false;

            }else return false;
        };

        priority_queue<vector<int>, vector<vector<int>> , decltype(cmp)> p(cmp);// arrival contraint there
        auto c=[](const vector<int>&a,const vector<int>&b){
            //where priority of a < prioority of b
            if(b[1]<a[1]) return true;
            else if(b[1]==a[1]){
                if (b[2]< a[2]) return true;
                else return false;
            }else return false;
        };

        // //no arrival constraint
         priority_queue<vector<int>,vector<vector<int>>, decltype(c)> q(c);

        for(int i=0;i<v.size();i++){
            p.push(v[i]);
           
        }

        int t=0;
        while(!p.empty()){
            if (t< p.top()[0] ) t++; //just increase the time
            else{
                // if(t>=q.top()[0]){
                //     t+=q.top()[1];
                //     ans.push_back(q.top()[2]);
                    
                // }
                // t+=p.top()[1];
                // ans.push_back(p.top()[2]);
                // p.pop();
                // stack<vector<int>> temp;
                // while(!p.empty()){
                //     if(p.top()[0]>t) break;
                //     vector<int> x=p.top();
                //     p.pop();
                //     x[0]=t;
                //     temp.push(x);
                // }
                // while(!temp.empty()){
                //     p.push(temp.top());
                //     temp.pop();
                // }

                while(!p.empty()){
                    if(p.top()[0]>t) break;
                    q.push(p.top());
                    p.pop();
                }

                t+=q.top()[1];
                ans.push_back(q.top()[2]);
                q.pop();
            }
        }

        while(!q.empty()){
            ans.push_back(q.top()[2]);
            q.pop();
        }

        return ans;


    }
};