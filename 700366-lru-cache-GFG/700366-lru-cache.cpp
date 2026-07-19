#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUCache {
  private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

  public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }

        if (cacheList.size() == capacity) {
            int lruKey = cacheList.back().first;
            cacheMap.erase(lruKey);
            cacheList.pop_back();
        }

        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna