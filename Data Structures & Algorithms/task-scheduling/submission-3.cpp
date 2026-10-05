class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq (26,0);
        for(char c: tasks){
            
            freq[c-'A']++;

        }
        auto cmp=[freq](int a , int b){
            return freq[a] < freq[b];
        };

        priority_queue<int, vector<int>, decltype(cmp)> p(cmp);

        
        
        unordered_map<int,int> stamps;

        for(int i=0;i<26;i++){
            if(freq[i]!=0) p.push(i);
            stamps[i]=0;
        }

        int i=0; //posiion
        queue <int> q;

        while(true){
            if(p.empty() && q.empty()) break;
            if(p.empty() && i<stamps[q.front()]) i=stamps[q.front()];
            else  i++;
            
            

            if(!q.empty() && stamps[q.front()]<=i && (p.empty() || !p.empty() && freq[p.top()]<=freq[q.front()])){
                int t=q.front();
                q.pop();
                freq[t]--;
                if(freq[t]!=0) {
                    q.push(t);
                    stamps[t]+=n+1;
                }
            }else if(!p.empty()){
                int t=p.top();
                p.pop();
                freq[t]--;
                if(freq[t]!=0){
                    stamps[t]=i+n+1;
                    q.push(t);
                }
            }

            if(p.empty() && q.empty()) break;

          
        }

        return i;


        
    }
};
