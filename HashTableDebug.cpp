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
    testTable1.insert("testkey59", 1100);
    testTable1.insert("testkey59", 1103);
    testTable1.insert("testkey3", 1100);
    std::cout << "After 3 adds" << std::endl;
    std::cout << testTable1;
    testTable1.insert("testkey4", 1100);
    testTable1.insert("testkey5", 1100);
    testTable1.insert("testkey6", 1100);
    std::cout << "After 6 adds" << std::endl;
    std::cout << testTable1;
    testTable1.insert("testkey7", 1100);
    testTable1.insert("testkey8", 1100);
    testTable1.insert("testkey9", 1100);

    std::cout << "After 9 adds" << std::endl;
    std::cout << testTable1;

    //testTable1.remove("testkey2");
    testTable1.remove("testkey4");
    bool contains = testTable1.contains("testkey2");

    std::cout << "----End Test----" << std::endl;

    return 0;
}