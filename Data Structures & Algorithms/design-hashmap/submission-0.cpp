class MyHashMap {
public:
    MyHashMap() {
        size = 10;
        elements = 0;
        buckets = vector<vector<pair<int, int>>>(size);
    }
    
    void put(int key, int value) {
        if (elements >= size * 0.75) {
            size *= 2;
            vector<vector<pair<int, int>>> newBuckets(size);

            for (const auto& bucket : buckets) {
                for (const auto& item : bucket) {
                    int rehash = hash(item.first);
                    newBuckets[rehash].push_back(item);
                }
            }

            buckets = newBuckets;
        }

        int idx = hash(key);

        for (auto& item : buckets[idx]) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }

        buckets[idx].push_back({key, value});
        elements++;
    }
    
    int get(int key) {
        int idx = hash(key);

        for (const auto& item : buckets[idx]) {
            if (item.first == key) return item.second;
        }

        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);

        for (auto& item : buckets[idx]) {
            if (item.first == key) {
                int length = buckets[idx].size();
                swap(item, buckets[idx][length - 1]);
                buckets[idx].pop_back();
                elements--;
                return;
            }
        }
    }

private:
    int size;
    int elements;
    vector<vector<pair<int, int>>> buckets;

    int hash(int key) {
        return key % size;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */