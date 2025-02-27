#include <vector>
#include <list>

class HashMap
{
public:
    HashMap()
    {
        table.resize(BUCKET);
    }
    
    void put(int key, int value)
    {
        auto& bucket = table[hashFunction(key)];
        for (auto& [k, v] : bucket)
        {
            if (k == key)  // If key exists, update
            {
                v = value;
                return;
            }
        }
        bucket.emplace_back(key, value); // Otherwise, add new pair
    }
    
    int get(int key)
    {
        auto& bucket = table[hashFunction(key)];
        for (auto& [k, v] : bucket)
        {
            if (k == key)
                return v;
        }
        return -1;  // Key not found
    }
    
    void remove(int key)
    {
        auto& bucket = table[hashFunction(key)];
        bucket.remove_if([key](const std::pair<int, int>& p) { return p.first == key; });
    }
    
    int hashFunction(int x)
    {
        return x % BUCKET;
    }

private:
    std::vector<std::list<std::pair<int, int>>> table;
    int BUCKET = 1000000;
};