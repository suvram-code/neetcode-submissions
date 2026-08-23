class MinStack {
    std::stack<int> s;
    std::stack<int> min;
    
public:
    MinStack() {
        min.push(pow(2,31)-1);
    }
    
    void push(int val) {
        s.push(val);
        if(val<=min.top()) min.push(val);
    }
    
    void pop() {
        if(s.top()==min.top()) min.pop();
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};
