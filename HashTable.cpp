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

//Hash Table Bucket Constructor with No Parameters (Empty Bucket)
HashTableBucket::HashTableBucket() {
    key = "nokeyhere";
    value = 0;
    type = BucketType::ESS;
}

//Hash Table Bucket Constructor with Parameters
HashTableBucket::HashTableBucket(const std::string &key, const size_t &value) {
    this->key = key;
    this->value = value;
    type = BucketType::Normal;
}

void HashTableBucket::load(const std::string& key, const size_t& value){
    this->key = key;
    this->value = value;
    type = BucketType::Normal;
}

bool HashTableBucket::isEmpty() const{
    if (type == BucketType::Normal){
        return false;
    }
    if (type == BucketType::ESS | type == BucketType::EAR){
        return true;
    }
    else {
        //throw exception
    }
}

std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket){
    os << ", Key: " << bucket.key;
    os << ", Value: " << bucket.value << "\n";
    return os;
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
            currentBucket.key = "nokeyhere";
            currentBucket.value = 0;
            currentBucket.type = HashTableBucket::BucketType::EAR;
            numOfInserts--;
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

//Get Method
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

//Operator [] Overload
size_t& HashTable::operator[](const std::string& key){
    //Hashing String input
    std::hash<std::string> myHash;
    size_t h = myHash(key);
    size_t index = h % tableData.size();

    bool notFound = true;
    size_t newHashTableIndex = 0;


    while (notFound){
        HashTableBucket &currentBucket = tableData.at(index);
        if ((currentBucket.type == HashTableBucket::BucketType::Normal) && (currentBucket.key == key)){
            return currentBucket.value;
        }

        if (currentBucket.type == HashTableBucket::BucketType::ESS){
            //Throw Exception
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

std::vector<std::string> HashTable::keys() const{
    //Creating new vector to hold keys
    std::vector<std::string> listOfKeys;

    for (const HashTableBucket &current : tableData){
        if (current.type == HashTableBucket::BucketType::Normal){
            listOfKeys.push_back(current.key);
        }

    }

    return listOfKeys;
}

//Alpha Method
double HashTable::alpha() const{
    if (tableData.empty()){
        return 0.0;
    } else {
        double alpha = 0.0;
        alpha = static_cast<double>(numOfInserts) / static_cast<double>(tableData.size());
        return alpha;
    }
}

size_t HashTable::capacity() const {
    return tableData.size();
}

size_t HashTable::size() const{
    return numOfInserts;
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
