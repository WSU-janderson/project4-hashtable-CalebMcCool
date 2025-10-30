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
    std::cout << testTable1.tableData.size() << std::endl;

    testTable1.insert("testkey", 1234);
    testTable1.insert("testkey2", 1233);
    testTable1.insert("testkey2", 1233);
    bool contains = testTable1.contains("testkey3");

    std::cout << "----Contains testkey2? ----" << std::endl;

    std::cout << "----End Test----" << std::endl;

    return 0;
}