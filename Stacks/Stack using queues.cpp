class MyStack {
public:
    std::queue<int> q;
    int sz = 0;
    MyStack() { 
    }
    
    void push(int x) {
        q.push(x);
        sz++;
    }
    
    int pop() {
        std::queue<int> qt = q;
        func(qt);
        int ans = qt.front();
        qt.pop();
        q = func(qt);
        sz--;
        return ans;
    }
    
    int top() {
        std::queue<int> qt = q;
        func(qt);
        int ans = qt.front();
        q = func(qt);
        return ans;        
    }
    
    bool empty() {
        if(sz > 0) return false;
        return true;
    }
    
    queue<int> func(std::queue<int>& qt) {
        if(qt.empty()) return qt;
        int x = qt.front();
        qt.pop();
        func(qt);
        qt.push(x);
        return qt;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
