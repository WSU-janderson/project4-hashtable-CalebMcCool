/** Hash Table Header File
 *  Creator: Caleb McCool
 *  Date: 10/27/2025
 *    This is the header file for the Hash Table class.
 *
 */

#ifndef HashTable_h
#define HashTable_h
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

/*
 * Hash Table Bucket class
 */

class HashTableBucket {
private:

public:
    //enum
    enum class BucketType {Normal, ESS, EAR};

    //Variables
    std::string key;
    size_t value;
    BucketType type;

    //Methods
    HashTableBucket();
    HashTableBucket(const std::string& key, const size_t& value);
    void load(const std::string& key, const size_t& value);
    bool isEmpty() const;
};

/*
 * Hash Table Class
 */
class HashTable {
private:

public:
    //Variables
    std::vector<HashTableBucket> tableData;
    std::vector<size_t> offsets;

    //Constructor [done]
    HashTable(size_t initCapacity = 8);

    //Insert Method
    bool insert(const std::string& key, const size_t& value);

    //Remove Method
    bool remove(const std::string& key);

    //Constaints Method
    bool contains(const std::string& key) const;

    //Get Method
    std::optional<size_t> get (const std::string& key) const;

    //[] Overload Method
    size_t& operator[](const std::string& key);

    //Hashing Algorithm Method
    size_t hash(const std::string& key);

    //Keys
    std::vector<std::string> keys() const;

    //Get Alpha Method
    double alpha() const;

    //Get Capacity Method
    size_t capacity() const;

    //Get Size Method
    size_t size() const;

    //-- Personal Methods --

    //next bucket according to offset vector
    HashTableBucket& nextBucket(size_t index);

    //next bucket with ESS or EAR
    HashTableBucket& nextEmptyBucket;

    //next bucket with ESS
    HashTableBucket& nextEmptySinceStart;




};

#endif