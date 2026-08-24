class StockSpanner {
    stack<int> m;
    int s;//size
    stack<int> pos;

public:
    StockSpanner() {
        m.push(100001);//sentinel
        pos.push(-1);
        s=0;
    }
    
    int next(int price) {
        int ans;
        if(price<m.top()){
            m.push(price);
            ans=s-pos.top();
            pos.push(s);
            s++;
        }else{
            while(price>=m.top()){
                pos.pop();
                m.pop();
            }
            m.push(price);
            ans=s-pos.top();
            pos.push(s);
            s++;
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */