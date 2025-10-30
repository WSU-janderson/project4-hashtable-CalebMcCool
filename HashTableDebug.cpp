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
    testTable1.insert("testke6y", 800);
    testTable1.insert("testke4y", 1200);
    testTable1.insert("testke3y", 1190);

    std::cout << testTable1;

    std::cout << "----New Table:----" << std::endl;
    testTable1["testkey"] = 888;

    std::cout << testTable1;

    std::cout << "----End Test----" << std::endl;

    return 0;
}