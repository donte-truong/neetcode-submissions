class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int topper = q.front();
        for (int i = 0; i < q.size() - 1; i++) {
            q.pop();
            q.push(topper);
            topper = q.front();
        }
        q.pop();
        return topper;
    }
    
    int top() {
        int topper;
        for (int i = 0; i < q.size(); i++) {
            topper = q.front();
            q.pop();
            q.push(topper);
        }
        return topper;
    }
    
    bool empty() {
        return q.empty();
    }

private:
    
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */