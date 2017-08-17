class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            used.erase(it->second.second);
            it->second.second = used.insert(used.end(), key);
            return it->second.first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            used.erase(it->second.second);
            it->second.first = value;
            it->second.second = used.insert(used.end(), key);
        } else {
            if (used.size() == cap) {
                hash.erase(used.front());
                used.pop_front();
            } 
            hash[key] = make_pair(value, used.insert(used.end(), key));
        }
    }
private:
    unordered_map<int, pair<int, list<int>::iterator>> hash;
    list<int> used;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
