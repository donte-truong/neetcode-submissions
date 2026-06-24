class FreqStack {

unordered_map<int, int> counts;
vector<stack<int>> stacks;

public:
    FreqStack() {
        stacks.push_back(stack<int>());
    }
    
    void push(int val) {
        
        int valCount = ++counts[val];

        if (valCount == stacks.size()) {
            stacks.push_back(stack<int>());
        }

        stacks[valCount].push(val);

    }
    
    int pop() {
        
        int freq = stacks.size() - 1;
        int res = stacks[freq].top();
        stacks[freq].pop();

        if (stacks[freq].empty()) {
            stacks.pop_back();
        }

        counts[res]--;
        return res;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */