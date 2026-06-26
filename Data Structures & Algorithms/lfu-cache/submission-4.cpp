class LFUCache {

    struct ListNode {
        int key;
        int val;
        int freq;
        ListNode* prev;
        ListNode* next;

        ListNode(int key, int val) : key(key), val(val), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct LinkedList {
        ListNode* left;
        ListNode* right;
        int size;

        LinkedList() {
            left = new ListNode(0, 0);
            right = new ListNode(0, 0);
            left->next = right;
            right-> prev = left;
            size = 0;
        }

        ~LinkedList() {
            delete left;
            delete right;
        }

        int length() {
            return size;
        }

        void pushRight(ListNode* node) {
            ListNode* prev = right->prev;
            prev->next = node;
            node->next = right;
            right->prev = node;
            node->prev = prev;
            size += 1;
        }

        void pop(ListNode* node) {
            ListNode* prev = node->prev;
            ListNode* next = node->next;
            prev->next = next;
            next->prev = prev;
            node->prev = nullptr;
            node->next = nullptr;
            size -= 1;
        }

        ListNode* popLeft() {
            ListNode* node = left->next;
            pop(node);
            return node;
        }
    };

    int capacity;
    int lfuCount;
    unordered_map<int, ListNode*> nodeMap;
    unordered_map<int, LinkedList*> listMap;

    void counter(ListNode* node) {
        int count = node->freq;
        listMap[count]->pop(node);

        if (count == lfuCount && listMap[count]->length() == 0) {
            listMap.erase(lfuCount++);
        }

        if (!listMap.contains(++count)) {
            listMap[count] = new LinkedList();
        }

        node->freq = count;
        listMap[count]->pushRight(node);
    }

public:
    LFUCache(int capacity) : capacity(capacity), lfuCount(0) {}
    
    int get(int key) {
        if (!nodeMap.contains(key))
            return -1;

        ListNode* node = nodeMap[key];
        counter(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if (nodeMap.contains(key)) {
            ListNode* node = nodeMap[key];
            node->val = value;
            counter(node);
            return;
        }

        if (nodeMap.size() == capacity) {
            ListNode* toRemove = listMap[lfuCount]->popLeft();
            nodeMap.erase(toRemove->key);
            if (listMap[lfuCount]->length() == 0)
                listMap.erase(lfuCount);
            delete toRemove;
        }

        ListNode* node = new ListNode(key, value);
        nodeMap[key] = node;

        if (!listMap.contains(1)) {
            listMap[1] = new LinkedList();
        }

        lfuCount = 1;
        listMap[1]->pushRight(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */