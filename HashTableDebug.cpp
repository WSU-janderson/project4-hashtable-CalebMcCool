/**
 * HashTableDebug.cpp
 *
 * Write your tests in this file
 */
#include <iostream>
#include "HashTable.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "----Test----" << std::endl;
    HashTable testTable1;

    testTable1.insert("testkey", 1100);
    testTable1.insert("testke8y", 10);

    std::cout << testTable1;

    testTable1.remove("testke8y");
    std::cout << testTable1;
    testTable1.insert("testke8y", 10);


    //std::cout << "----New Table:----" << std::endl;
    //testTable1["testkey"] = 888;

    std::cout << testTable1;
    size_t test = testTable1.capacity();
    size_t sizeTest = testTable1.size();

    std::cout << "----End Test----" << std::endl;

    return 0;
}