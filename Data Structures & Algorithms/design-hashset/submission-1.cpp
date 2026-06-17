class MyHashSet {
public:
    MyHashSet() {
        elements = 0;
        size = 10;
        buckets = vector<vector<int>>(size);
    }
    
    void add(int key) {
        if (elements >= buckets.size() * 0.75) {
            size = buckets.size() * 2;
            vector<vector<int>> newBuckets(size);
            for (auto& bucket : buckets) {
                for (auto& key : bucket) {
                    int rehash = hash(key);
                    newBuckets[rehash].push_back(key);
                }
            }
            buckets = newBuckets;
        }

        if (contains(key)) return;

        int idx = hash(key);
        buckets[idx].push_back(key);
        elements += 1;
    }
    
    void remove(int key) {
        int idx = hash(key);

        for (auto& value : buckets[idx]) {
            if (value == key) {
                int length = buckets[idx].size();
                swap(value, buckets[idx][length - 1]);
                buckets[idx].pop_back();

                elements--;
                return;
            }
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);

        for (const auto& value : buckets[idx]) {
            if (value == key) return true;
        }
        
        return false;
    }

private:
    vector<vector<int>> buckets;
    int size;
    int elements;

    int hash(int key) {
        return key % size;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */