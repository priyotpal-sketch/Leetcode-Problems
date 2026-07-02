class LRUCache {
public:
    
    list<pair<int,int>> l;  
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];
        int value = it->second;

        
        l.erase(it);
        l.push_front({key, value});
        mp[key] = l.begin();

        return value;
    }
    
    void put(int key, int value) {

        
        if(mp.find(key) != mp.end()) {
            l.erase(mp[key]);
        }

        
        l.push_front({key, value});
        mp[key] = l.begin();

        
        if(l.size() > capacity) {
            auto last = l.back();
            int keyToDelete = last.first;

            l.pop_back();
            mp.erase(keyToDelete);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */