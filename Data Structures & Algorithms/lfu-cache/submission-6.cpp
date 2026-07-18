class LFUCache {

    struct Node {
        int key;
        int val;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct LinkedList {
        Node* head;
        Node* tail;
        int size;

        LinkedList() {
            head = new Node(0, 0);
            tail = new Node(0, 0);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        ~LinkedList() {
            delete head;
            delete tail;
        }

        void add(Node* node) {
            Node* last = tail->prev;
            last->next = node;
            tail->prev = node;
            node->next = tail;
            node->prev = last;
            size++;
        }

        void pop(Node* node) {
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;

            node->prev = nullptr;
            node->next = nullptr;

            size--;
        }

        Node* popLeft() {
            if (size == 0) return nullptr;

            Node* node = head->next;
            pop(node);
            return node;
        }
    };

    int capacity;
    int minFreq;
    unordered_map<int, Node*> nodeMap;
    unordered_map<int, LinkedList*> freqMap;

    void counter(Node* node) {
        int freq = node->freq;
        LinkedList* lst = freqMap[freq];

        lst->pop(node);

        if (freq == minFreq && freqMap[freq]->size == 0)
            minFreq++; 

        if (!freqMap.contains(++freq))
            freqMap[freq] = new LinkedList();

        LinkedList* newLst = freqMap[freq];
        node->freq++;
        newLst->add(node);
    }

    void evict() {
        Node* node = freqMap[minFreq]->popLeft();
        nodeMap.erase(node->key);
        delete node;
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    ~LFUCache() {
        for (auto& item : nodeMap) {
            delete item.second;
        }
        for (auto& item : freqMap) {
            delete item.second;
        }
    }
    
    int get(int key) {
        if (!nodeMap.contains(key))
            return -1;

        Node* node = nodeMap[key];
        counter(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (nodeMap.contains(key)) {
            nodeMap[key]->val = value;
            counter(nodeMap[key]);
            return;
        }

        if (nodeMap.size() == capacity)
            evict();

        Node* node = new Node(key, value);
        nodeMap[key] = node;
        minFreq = 1;

        if (!freqMap.contains(minFreq))
            freqMap[minFreq] = new LinkedList();

        freqMap[minFreq]->add(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */