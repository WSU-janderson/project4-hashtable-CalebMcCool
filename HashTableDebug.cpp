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

    testTable1.insert("testkey", 1100);
    testTable1.insert("testkey2", 6677);
    testTable1.insert("testkey3", 0033);
    testTable1.insert("testkey4", 4444);
    testTable1.insert("testkey5", 2121);
    testTable1.insert("testkey6", 3535);
    testTable1.insert("testkey6", 7777);

    bool contains = testTable1.contains("testkey3");

    std::cout << testTable1;

    //bool removed = testTable1.remove("testkey2");

    std::cout << "----End Test----" << std::endl;

    return 0;
}