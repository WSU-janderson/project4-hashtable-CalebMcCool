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
}

// UNFINISHED
// Replace % 8 with actual size function once implemented
bool HashTable::insert(const std::string &key, const size_t &value) {
    //Hashing key and Retrieving Home Position
    std::hash<std::string> myHash;
    size_t h = myHash(key);
    size_t index = h % tableData.size();

    //Adding key to Table
    HashTableBucket& currentBucket = tableData.at(index);



    bool notPositioned = true;

    size_t offsetIndex = 0;
    for (size_t i : offsets){
        if (i == index){
            break;
        }
        offsetIndex++;
    }

    size_t offsetIncrement = index;
    while (notPositioned) {
        //If the bucket is empty since start, insert key value pair.
        if (currentBucket.type == HashTableBucket::BucketType::ESS) {
            currentBucket.key = key;
            currentBucket.value = value;
            currentBucket.type = HashTableBucket::BucketType::Normal;
            break;
        }

        //If the bucket is empty after removal, insert key value pair
        else if (currentBucket.type == HashTableBucket::BucketType::EAR) {
            currentBucket.key = key;
            currentBucket.value = value;
            currentBucket.type = HashTableBucket::BucketType::Normal;
            break;
        }

        //If the bucket is normal (occupied), go to next index
        else {
            if (offsetIncrement > offsets.size()){
                offsetIncrement = offsets.at(0);
            }

            currentBucket = tableData.at(offsetIncrement);
            continue;
        }
    }



    return false;
}

HashTableBucket& HashTable::nextBucket(size_t index){

}