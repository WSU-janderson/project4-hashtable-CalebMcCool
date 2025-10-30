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
    testTable1.insert("testKey334", 5000);

    std::cout << "----Test Table 1----" << std::endl;
    //for (size_t i=0; i<testTable1.tableData.size(); i++){
        //std::cout << testTable1.tableData.at(i) << std::endl;
    //}
    std::cout << "----End Test----" << std::endl;

    return 0;
}