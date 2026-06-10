#include <iostream>
#include <vector>
#include <string>
#include <list>

//Twarimitswe Aaron 
//Igihozo Belise
//Kamana Clare

using namespace std;

// A generic Hash Table implementation handling its own load factor and rehashing
template <typename K, typename V>
class HashTable {
private:
    struct HashNode {
        K key;
        V value;
        HashNode(K key, V value) : key(key), value(value) {}
    };

    // Array of linked lists for separate chaining to handle collisions
    vector<list<HashNode>> table;
    size_t numElements;
    size_t tableSize;
    
    const double MAX_LOAD_FACTOR = 0.75; 

    size_t hashFunction(const K& key) {
        return hash<K>{}(key) % tableSize;
    }

    void rehash() {
        size_t oldSize = tableSize;
        tableSize *= 2; // Double the array size
        
        cout << "[REHASHING LOG] Load factor exceeded " << MAX_LOAD_FACTOR << " (Current Elements: " << numElements << ")." << endl;
        cout << " -> Reallocating memory: Doubling buckets from " << oldSize << " to " << tableSize << "." << endl;

        // Create new table with doubled size
        vector<list<HashNode>> newTable(tableSize);

        // Re-map existing components
        for (size_t i = 0; i < oldSize; i++) {
            for (auto& node : table[i]) {
                size_t newIndex = hashFunction(node.key);
                newTable[newIndex].push_back(node);
            }
        }

        // Move the new table to replace the old one
        table = move(newTable);
    }

public:
    HashTable(size_t size = 16) {
        tableSize = size;
        numElements = 0;
        table.resize(tableSize);
        cout << "[INIT LOG] Hash table created with initial capacity of " << tableSize << " buckets." << endl;
    }

    // Calculate Current Load Factor (alpha = items / table size)
    double getLoadFactor() {
        return (double)numElements / tableSize;
    }

    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key);
        
        // Update value if key already exists
        for (auto& node : table[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }

        // Insert new component
        table[index].emplace_back(key, value);
        numElements++;

        // Trigger automatic rehashing if load factor threshold is exceeded
        if (getLoadFactor() > MAX_LOAD_FACTOR) {
            rehash();
        }
    }

    bool get(const K& key, V& value) {
        size_t index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                value = node.value;
                return true;
            }
        }
        return false;
    }
    
    void remove(const K& key) {
        size_t index = hashFunction(key);
        auto& cell = table[index];
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->key == key) {
                cell.erase(it);
                numElements--;
                return;
            }
        }
    }

    size_t size() {
        return numElements;
    }
    
    size_t capacity() {
        return tableSize;
    }
};

int main() {
    cout << "=== Hash Table Memory Allocation & Load Factor Optimization ===" << endl;
    
    // Initialize with a small capacity to trigger multiple rehashes easily
    HashTable<string, int> ht(8); 

    int numItemsToInsert = 100000;
    cout << "\nStarting insertion of " << numItemsToInsert << " items to test dynamic memory allocation..." << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for (int i = 1; i <= numItemsToInsert; i++) {
        ht.insert("key_" + to_string(i), i);
        
        // Print progress for the first few powers of 10 to show it's working without spamming
        if (i == 100 || i == 1000 || i == 10000 || i == 50000) {
            cout << "[PROGRESS] Inserted " << i << " items. Current load factor: " << ht.getLoadFactor() << endl;
        }
    }

    cout << "-------------------------------------------------------------------" << endl;
    cout << "Finished insertion test." << endl;
    cout << "Final capacity (buckets): " << ht.capacity() << endl;
    cout << "Final Total Elements: " << ht.size() << endl;
    cout << "Final Load Factor: " << ht.getLoadFactor() << endl;
    cout << "===================================================================" << endl;

    return 0;
}
