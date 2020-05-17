//U98285639
//Nafis Abeer


#include <vector>
#include "hw5.h"

using namespace std;

// (a)

std::vector<int> findMinK(const int k, const std::vector<int> &min_heap){
    /*int index = k;   // for the index of the elements in heap when being probed
    int counter = 0; // checks to see what level of the heap k lies on

    /*int parent(int i) { // function for parent of index
        if(i % 2 == 1)
            return (i+1)/2 - 1;
        else
            return i/2 - 1;
    };

    auto left = [] (int i) { // function for left child of index
        return 2 * i + 1;
    };

    auto right = [] (int i) { // function for right child of index
        return 2 * i + 2;
    }; 
    // can't have function inside function and I can't imclude my header file in solution :/

    while (index != 0)
    { //goes through and raises counter to level of k - 1
        counter++;
        if (index % 2 == 1)
        {
            index = (index + 1) / 2 - 1;
        }
        else
        {
            index = index / 2 - 1;
        }
        //index = parent(index);  would have been clean
    }

    vector<int> storageheap; // mini-min_heap to store candidates for smallest elements

    int rowindex = 1;  // will be needed for loop below
    int childrenindex; // will be needed for loop below

    //the below for-loop will run as many times as counter... the reason for this is k is probably a child of the last row and all the children will be stored for that row
    for (int i = 0; i < counter - 1; i++)
    { //goes through and copies min_heap up to level counter onto mini min_heap... intentionally copies more data then needed
        if (i == 0)
        { // root case
            storageheap.push_back(min_heap[i]);
            int j = 0;
            if(k > 2){
                childrenindex = 2 * j + 1;
                storageheap.push_back(min_heap[childrenindex]);
                childrenindex = 2 * j + 2; // right(j);  would've looked clean :/
                storageheap.push_back(min_heap[childrenindex]);
            }
            else if(k > 1){
                childrenindex = 2 * j + 1;
                storageheap.push_back(min_heap[childrenindex]);
            }
            else{
                continue;
            }
        }
        else
        {
            int loops = i * 2;
            for (int j = rowindex; j < rowindex + loops; j++)
            {                              //assigns children to parents in current row by running for every index in that row
                childrenindex = 2 * j + 1; // left(j);  would've looked clean
                storageheap.push_back(min_heap[childrenindex]);
                childrenindex = 2 * j + 2; // right(j);  would've looked clean :/
                storageheap.push_back(min_heap[childrenindex]);
            }
            rowindex = rowindex + loops; // increases index to next row
        }
    } // this only copies values up to the level before the last level. This is a precaution in case the heap is not complete

    int sizeofstorage = storageheap.size();
    int sizeofmin = min_heap.size();

    int parentoflastindex;

    if (sizeofmin % 2 == 1)
    {
        parentoflastindex = (sizeofstorage + 1) / 2 - 1;
    }
    else
    {
        parentoflastindex = sizeofstorage / 2 - 1;
    }

    for (int j = rowindex; j <= parentoflastindex; j++)
    {                              // copies children of the last row of parents
        childrenindex = 2 * j + 1; // left(j);  would've looked clean
        storageheap.push_back(min_heap[childrenindex]);
        childrenindex = 2 * j + 2; // right(j);  would've looked clean :/
        storageheap.push_back(min_heap[childrenindex]);
    }*/

    //I'm tired of the segfaults

    vector<int> storageheap; // mini-min_heap to store candidates for smallest elements

    for(int i = 0; i < k; i++){
        storageheap.push_back(min_heap[i]);
    }

    //need a for loop to check if any of the values left in min_heap are smaller than the values in current storage_heap
    //if such values exist add them on to storage heap then sort the storage_heap and return values up to k in the form of a new vector

    int sizeofstorage = storageheap.size();
    int sizeofmin = min_heap.size();

    for (int i = 0; i < k; i++)
    {
        for (int j = k; j < sizeofmin; j++)
        {
            if (storageheap[i] > min_heap[j])
            {
                //storageheap.push_back(min_heap[j]); // if additional small values are found add them onto storage heap
                int temp = storageheap[i];
                storageheap[i] = min_heap[j];
                storageheap.push_back(temp);
            }
            else
            {
                continue;
            }
        }
    }

    //storageheap now contains all potential candidates for k smallest elements
    //double for loop to sort it out before sending it as output

    

    /*for (int i = 0; i < k; i++)
    {
        int valuetobestored; // integer to hold smallest value
        int index_of_val;    // index needed to pop smallest element out of storage heap
        valuetobestored = *min_element(storageheap.begin(), storageheap.end());
        resultvec.push_back(valuetobestored);
        if(k > 2){
            index_of_val = distance(storageheap.begin(), min_element(storageheap.begin(), storageheap.end()));
            storageheap.erase(storageheap.begin() + index_of_val - 1);
        }
    }*/


    for(int i; i < sizeofstorage; i++){
        for(int j = i; j < sizeofstorage; j++){
            if(storageheap[i] > storageheap[j]){
                swap(storageheap[i], storageheap[j]);
            }
        }
    }

    vector<int> resultvec;

    for(int i = 0; i < k; i++){
        resultvec.push_back(storageheap[i]);
    }


    return resultvec; // you will need to change this
}

// (b)

class SillyHashFun : public HashFun {
    unsigned int operator()(const std::string& key) {
        // Here's my silly hash function that always returns 0.
        // You should make some good hash functions and not use this one.
        // This is just an example of how to inherit the HashFun class.
        return 0;
    }
};

class GoodHashFun_0 : public HashFun {
    unsigned int operator()(const std::string& key) {
        // You've seen my silly hash function above.
        // Your good hash function should go here!

        return 0; // You'll need to change this
    }
};

class SDBMHash : public HashFun
{
    unsigned int operator()(const std::string &key)
    {
        int len = key.length();
        unsigned int hash = 0;
        unsigned int i = 0;

        for (i = 0; i < len; i++)
        {
            hash = key[i] + (hash << 6) + (hash << 16) - hash;
        }

        return (hash & 0x6FFFFFFF);
    }
};

class DJBHash : public HashFun
{
    unsigned int operator()(const std::string &key)
    {
        int len = key.length();
        unsigned int hash = 5381;
        unsigned int i = 0;

        for (i = 0; i < len; i++)
        {
            hash = ((hash << 5) + hash) + key[i];
        }

        return (hash & 0x6FFFFFFF);
    }
};

class APHash : public HashFun
{
    unsigned int operator()(const std::string &key){
        int len = key.length();
        unsigned int hash = 0x6FFFFFFF;
        unsigned int i = 0;

        for (i = 0; i < len; i++)
        {
            hash ^= ((i & 1) == 0) ? ((hash << 7) ^ (key[i]) * (hash >> 3)) : (~((hash << 11) + ((key[i]) ^ (hash >> 5))));
        }

        return (hash);
    }
};

// ...
// You can make as many hash functions as you want!
// ...

void BloomFilter::add_hash_funs() {
    // You will need to implement this function, it is responsible
    // for adding your custom hash functions to your bloom filter.

    // Here's an example where I add two hash functions.
    // You will need to add at least one hash function.
    SDBMHash *h1 = new SDBMHash();
    DJBHash *h2 = new DJBHash();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
}

void BloomFilter::insert(const std::string& key) {
    // You will need to implement this function, it is responsible
    // for inserting key into the bloom filter.

    // Here's how you can call your hash functions that you added in add_hash_funs()
    //unsigned int first_hash_result = this->call_hash(0, key);
    // std::cout << "Hash of '" << key << "' is '" << first_hash_result << "' using the first hash function." << std::endl;
    //unsigned int second_hash_result = this->call_hash(1, key);
    // std::cout << "Hash of '" << key << "' is '" << second_hash_result << "' using the second hash function." << std::endl;

    // You'll need to use the results of the hash function to update this->filter
    // Here's an example
    //(this->filter)[first_hash_result % 330] = 1;
    //(this->filter)[second_hash_result % 330] = 1;

    int len = hash_funs.size();
    
    for (int i = 0; i < len; i++)
    {

        int result = this->call_hash(i, key) % 330;

        (this->filter)[result] = 1;
    }
}

bool BloomFilter::member(const std::string& key) {
    // This function should report true if key is potentially in the bloom filter.
    // It should only return false if you know for sure that key is not in the bloom filter.

    bool keypresent = true;
    int len = hash_funs.size();
    
    for (int i = 0; i < len; i++){
        int result = this->call_hash(i, key) % 330;
        if((this->filter)[result] == 0){
            keypresent = false;
        }
    } 
    
    
    
    if (keypresent == 1)
    {
        return true;
    }
    else{
        return false;
    }
}