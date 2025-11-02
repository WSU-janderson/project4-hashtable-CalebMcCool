[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7RAFczHS)
# Project 4 - HashTable

Project description can be found [in the repo](Project4_HashTable.pdf)

Place your complexity analysis below.

## insert()
This has a worst-case time complexity of O(n). As the while loop is 
going, it is probing each bucket. If all buckets are full, the probing
would need to scope the entire table. 

## remove()
This has a worst-case time complexity of O(n). This operates almost the
same as insert, so if the whole table is full, it needs to probe every bucket.

## constains()
This also has a worst-case time complexity of O(n). This function operates
similar to the other two and needs to possible check the entire table
before finding the target. 

## get()
The worst-case time complexity is O(n) because it performs the same probing
as the other two and could possibly probe the whole table. 

## operator[]
The worst-case time complexity is O(n) due to this function also using the same
techniques as the other methods to search the table. 


---