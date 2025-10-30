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
    numOfInserts = 0;

    //TESTING TESTING TESTING TETING TESTING
    for (size_t i=0; i < offsets.size(); i++){
        std::cout << offsets.at(i) << std::endl;
    }
}

bool HashTable::insert(const std::string &key, const size_t &value) {
    //Checking for Duplicates
    if (this->contains(key)){
        return false;
    }

    //Hashing key and Retrieving Home Position
    std::hash<std::string> myHash;
    size_t h = myHash(key);
    size_t index = h % tableData.size();

    //Inserting Key Value Pair into the Vector
    bool notPositioned = true;
    size_t newHashTableIndex = 0;

    while(notPositioned) {
        HashTableBucket &currentBucket = tableData.at(index);

        if (currentBucket.type == HashTableBucket::BucketType::ESS) {
            currentBucket.key = key;
            currentBucket.value = value;
            currentBucket.type = HashTableBucket::BucketType::Normal;
            numOfInserts++;
            break;
        }
        if (currentBucket.type == HashTableBucket::BucketType::EAR) {
            currentBucket.key = key;
            currentBucket.value = value;
            currentBucket.type = HashTableBucket::BucketType::Normal;
            numOfInserts++;
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
            if (offsetIndex >= offsets.size()) {
                offsetIndex = 0;
            }

            newHashTableIndex = offsets.at(offsetIndex);
            index = newHashTableIndex;
        }
    }

    //Increasing Size if Needed
    if (alpha() >= 0.5){

        //Creating new table
        std::vector<HashTableBucket> tempTable = tableData;
        size_t newSize = tableData.size() * 2;
        tableData.clear();
        tableData.resize(newSize);

        //Updating Offset vector
        offsets.clear();
        for (size_t i=0; i<newSize; i++){
            offsets.push_back(i);
        }
        std::random_device randomDevice;
        std::mt19937 generator(randomDevice());
        std::shuffle(offsets.begin(), offsets.end(), generator);



        //Re-hashing old values
        numOfInserts = 0;
        for(HashTableBucket &current : tempTable){
            if (current.type == HashTableBucket::BucketType::Normal){
                insert(current.key, current.value);
            }
        }

    }


    return true;
}

bool HashTable::contains(const std::string& key) const{
    //Hashing key and Retrieving Home Position
    std::hash<std::string> myHash;
    size_t h = myHash(key);
    size_t index = h % tableData.size();

    bool notFound = true;
    size_t newHashTableIndex = 0;


    while (notFound){
        const HashTableBucket &currentBucket = tableData.at(index);
        if ((currentBucket.type == HashTableBucket::BucketType::Normal) && (currentBucket.key == key)){
            return true;
        }

        if (currentBucket.type == HashTableBucket::BucketType::ESS){
            return false;
        }

        else {
            size_t offsetIndex = 0;
            for (size_t i=0; i<offsets.size(); i++){
                if (offsets.at(i) == index){
                    offsetIndex = i;
                    break;
                }
            }

            offsetIndex = offsetIndex + 1;
            if (offsetIndex >= offsets.size()) {
                offsetIndex = 0;
            }

            newHashTableIndex = offsets.at(offsetIndex);
            index = newHashTableIndex;
        }
    }
    return false;
}

bool HashTable::remove(const std::string& key){
    //Hashing String input
    std::hash<std::string> myHash;
    size_t h = myHash(key);
    size_t index = h % tableData.size();

    bool notFound = true;
    size_t newHashTableIndex = 0;


    while (notFound){
        HashTableBucket &currentBucket = tableData.at(index);
        if ((currentBucket.type == HashTableBucket::BucketType::Normal) && (currentBucket.key == key)){
            currentBucket.type = HashTableBucket::BucketType::EAR;
            return true;
        }

        if (currentBucket.type == HashTableBucket::BucketType::ESS){
            return false;
        }

        else {
            size_t offsetIndex = 0;
            for (size_t i=0; i<offsets.size(); i++){
                if (offsets.at(i) == index){
                    offsetIndex = i;
                    break;
                }
            }

            offsetIndex = offsetIndex + 1;
            if (offsetIndex >= offsets.size()) {
                offsetIndex = 0;
            }

            newHashTableIndex = offsets.at(offsetIndex);
            index = newHashTableIndex;
        }
    }
    return false;
}

std::optional<size_t> HashTable::get(const std::string& key) const {
    //Hashing String input
    std::hash<std::string> myHash;
    size_t h = myHash(key);
    size_t index = h % tableData.size();

    bool notFound = true;
    size_t newHashTableIndex = 0;


    while (notFound){
        const HashTableBucket &currentBucket = tableData.at(index);
        if ((currentBucket.type == HashTableBucket::BucketType::Normal) && (currentBucket.key == key)){
            return currentBucket.value;
        }

        if (currentBucket.type == HashTableBucket::BucketType::ESS){
            return std::nullopt;
        }

        else {
            size_t offsetIndex = 0;
            for (size_t i=0; i<offsets.size(); i++){
                if (offsets.at(i) == index){
                    offsetIndex = i;
                    break;
                }
            }

            offsetIndex = offsetIndex + 1;
            if (offsetIndex >= offsets.size()) {
                offsetIndex = 0;
            }

            newHashTableIndex = offsets.at(offsetIndex);
            index = newHashTableIndex;
        }
    }
}

double HashTable::alpha() const{
    if (tableData.empty()){
        return 0.0;
    } else {
        double alpha = 0.0;
        alpha = static_cast<double>(numOfInserts) /static_cast<double>(tableData.size());
        return alpha;
    }
}

std::ostream& operator<<(std::ostream& os, const HashTable& hashTable){
    for (size_t i=0; i<hashTable.tableData.size(); i++ ){
        HashTableBucket currentBucket = hashTable.tableData.at(i);
        os << "Bucket: " << i;
        os << ", Key: " << currentBucket.key;
        os << ", Value: " << currentBucket.value << "\n";
    }

    return os;
}
