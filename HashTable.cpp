/** Hash Table Class
 *  Creator: Caleb McCool
 *  Date: 10/27/2025
 *    This class implmenets a Hash Table
 */

#include "HashTable.h"
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>

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

    //Creating Psuedo-Random Offset Vector
        //Filling vector with incrementing size_t.
        for (size_t i=0; i<initCapacity; i++){
            offsets.push_back(i);
        }

        //Shuffling Vector in Random Order
        // (Recieved Information from cppreference)
        std::random_device randomDevice;
        std::mt19937 generator(randomDevice());
        std::shuffle(offsets.begin(), offsets.end(), generator);

    //Filling Table with Buckets
    for (size_t i=0; i<initCapacity; i++){
        HashTableBucket bucket;
        tableData.push_back(bucket);
    }

    //TESTING TESTING TESTING TETING TESTING
    for (size_t i=0; i < offsets.size(); i++){
        std::cout << offsets.at(i) << std::endl;
    }
}

// UNFINISHED
// Replace % 8 with actual size function once implemented
bool HashTable::insert(const std::string &key, const size_t &value) {
    //Hashing key and Retrieving Home Position
    std::hash<std::string> myHash;
    size_t h = myHash(key);
    size_t index = h % tableData.size();


bool notPositioned = true;
size_t newHashTableIndex = 0;
    HashTableBucket &currentBucket = tableData.at(index);
while(notPositioned) {
    if (currentBucket.type == HashTableBucket::BucketType::ESS) {
        currentBucket.key = key;
        currentBucket.value = value;
        currentBucket.type = HashTableBucket::BucketType::Normal;
        break;
    }
    if (currentBucket.type == HashTableBucket::BucketType::EAR) {
        currentBucket.key = key;
        currentBucket.value = value;
        currentBucket.type = HashTableBucket::BucketType::Normal;
        break;

    }
    if (currentBucket.type == HashTableBucket::BucketType::Normal) {
        //Search Offset Vector for Home Index of Hash Table
        size_t offsetIndex = 0;
        for (size_t i = 0; i < offsets.size(); i++) {
            if (offsets.at(i) == index) {
                offsetIndex = i;
                break;
            }
        }

        //Increment Offset Vector Position by 1
        offsetIndex = offsetIndex + 1;
        if (offsetIndex > offsets.size()) {
            offsetIndex = 0;
        }

        newHashTableIndex = offsets.at(offsetIndex);
        currentBucket = tableData.at(newHashTableIndex);
    }
}




    return false;
}

HashTableBucket& HashTable::nextBucket(size_t index){
    HashTableBucket currentBucket;

    return currentBucket;
}