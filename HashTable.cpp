/** Hash Table Class
 *  Creator: Caleb McCool
 *  Date: 10/27/2025
 *    This class implmenets a Hash Table
 */

#include "HashTable.h"
#include <iostream>
#include <string>
#include <random>

HashTableBucket::HashTableBucket() {
    key = "nokeyhere";
    value = 0;
    type = BucketType::ESS;
}

HashTableBucket::HashTableBucket(const std::string &key, const size_t &value) {
    this->key = key;
    this->value = value;
    type = BucketType::Normal;
}

HashTable::HashTable(size_t initCapacity){

    for (size_t i=0; i<initCapacity; i++){
        HashTableBucket bucket;
        tableData.push_back(bucket);
    }
}

// UNFINISHED
bool HashTable::insert(const std::string &key, const size_t &value) {
    size_t hashedKey = 0;
    hashedKey = hash(key);

}

// UNFINISHED
size_t HashTable::hash(const std::string& key){
    size_t hash = 0;
    for (char c:key){
        //static cast making sure the int is unsigned
        hash += static_cast<unsigned char>(c);
    }
    hash = hash % tableData.size();
    return hash;
}