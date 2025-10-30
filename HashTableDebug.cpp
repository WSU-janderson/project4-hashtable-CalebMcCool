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
    testTable1.insert("something else", 7777);
    testTable1.insert("testkey487", 10);
    std::cout << testTable1;


    auto keyValue = testTable1.get("something else");

    testTable1.insert("testkey487", 1440);
    testTable1.insert("testkey488", 120);
    testTable1.insert("testkey489", 180);
    testTable1.insert("testkey482", 109);
    testTable1.insert("testkey483", 120);
    testTable1.insert("testkey484", 1770);
    testTable1.insert("testkey485", 109);
    testTable1.insert("testkey486", 108);

    keyValue = testTable1.get("something else");

    keyValue = testTable1.get("testkey486");

    testTable1.remove("testkey486");

    std::cout << "----End Test----" << std::endl;

    return 0;
}