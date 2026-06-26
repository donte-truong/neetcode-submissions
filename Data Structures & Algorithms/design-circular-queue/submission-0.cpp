class MyCircularQueue {
private:
    vector<int> q;
    int head;
    int tail;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        q.resize(k);
        head = 0;
        tail = 0;
        size = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        q[tail] = value;
        tail = (tail + 1) % capacity;
        size += 1;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        head = (head + 1) % capacity;
        size -= 1;

        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;

        return q[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;

        return q[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */