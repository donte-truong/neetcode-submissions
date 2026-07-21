class LRUCache {
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
        Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

    unordered_map<int, Node*> nodeMap;
    int cap;

    void pop(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void pushRight(Node* node) {
        Node* last = tail->prev;
        last->next = node;
        tail->prev = node;
        node->prev = last;
        node->next = tail;
    }

    void evict() {
        if (nodeMap.size() <= 0)
            return;

        Node* node = head->next;
        head->next = node->next;
        node->next->prev = head;
        
        nodeMap.erase(node->key);
        delete node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        Node* curr = head;

        if (!nodeMap.contains(key))
            return -1;

        Node* node = nodeMap[key];
        pop(node);
        pushRight(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (nodeMap.contains(key)) {
            Node* node = nodeMap[key];
            node->val = value;
            pop(node);
            pushRight(node);
            return;
        }

        while (nodeMap.size() >= cap)
            evict();
        
        Node* node = new Node(key, value);
        nodeMap[key] = node;
        pushRight(node);
    }
};
