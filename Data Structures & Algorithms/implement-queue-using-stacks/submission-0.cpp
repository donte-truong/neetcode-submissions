class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        forward.push(x);
    }
    
    int pop() {
        while (!forward.empty()) {
            int topper = forward.top();
            forward.pop();

            backward.push(topper);
        }

        int ans = backward.top();
        backward.pop();

        while (!backward.empty()) {
            int topper = backward.top();
            backward.pop();
            
            forward.push(topper);
        }

        return ans;
    }
    
    int peek() {
        while (!forward.empty()) {
            int topper = forward.top();
            forward.pop();

            backward.push(topper);
        }

        int ans = backward.top();

        while (!backward.empty()) {
            int topper = backward.top();
            backward.pop();
            
            forward.push(topper);
        }

        return ans;
    }
    
    bool empty() {
        return forward.empty();
    }

private:
    stack<int> forward;
    stack<int> backward;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */