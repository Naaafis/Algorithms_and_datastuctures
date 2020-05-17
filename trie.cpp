//LATE DAY

//Nafis Abeer U98285639

#include <string>
#include "trie.h"

using namespace std;

void Trie::insert(string key, int val) {

    TrieNode* curr = root; // start at the root of the tree

    for(int i = 0; i < key.length(); i++){ // loop through the key letter by letter. If a children node does not exist for a certain sequence of letters make a new path down
        if(curr->children[key[i] - 'a'] == NULL){ // the [i] - 'a' chooses letters based on its index value. If key[i] is equal to 'a' then it chooses to follow down the path of children[0]
            curr->children[key[i] - 'a'] = new TrieNode();
            tree_size = tree_size + 1; // increase the size of tree to account for added letter
        }

        curr = curr->children[key[i] - 'a'] ; // move down a level to key[i]'s index 
    }

    curr->val = val;
    map_size = map_size + 1;


}

int Trie::search(string key) {
    TrieNode *curr = root; // start at the root of the tree

    for (int i = 0; i < key.length(); i++){ // loop through the key letter by letter. If a children node does not exist for a certain sequence of letters that means the key does not exist
        if (curr->children[key[i] - 'a'] == NULL){ // the [i] - 'a' chooses letters based on its index value. 
            return 0; // 0 in this case signifies that the key does not exist in the tree because part of the key was not found while probing the tree
        }
        curr = curr->children[key[i] - 'a']; //continue down the path of the key's letters
    }// if the end of the loop is reached that means the key exists

    return curr->val;
}

int getIndex(char ch){
    return ch - 'a';
}


bool hasnochildren(TrieNode* Node){
    for (int i = 0; i < 26; i++){
        if (Node->children[i]){
            return 0;
        }
        return 1;
    
    }
}

int totaltreesizedelete = 0;
int leafnode = 0;

TrieNode* deleteHelper(string key, TrieNode* CurrentNode, int length, int level){
    //bool deletedself = 0;
    leafnode++;

    if(!CurrentNode){
        return NULL; //deletedself;
    }

    if (level == length)
    {
        if (hasnochildren(CurrentNode) && CurrentNode->val == 0)
        {
            delete (CurrentNode);
            //deletedself = true;
            totaltreesizedelete++;
            CurrentNode = NULL;
        }
        //CurrentNode->val = 0;
        //deletedself = 0;

        //}
        return CurrentNode;
    }


    int i = key[level] - 'a';

    if (CurrentNode->children[key[level] - 'a'] && leafnode == length)
    {
        CurrentNode->children[key[level] - 'a']->val = 0;
    }

    
    CurrentNode->children[i] = deleteHelper(key, CurrentNode->children[i], length, level + 1);



    return CurrentNode;
    /*else {
        TrieNode* childNode = CurrentNode->children[key[level] - 'a'];
        bool childDeleted = deleteHelper(key, childNode, length, level + 1);

        if(childDeleted){
            CurrentNode->children[key[level] - 'a'] = NULL;
            if(!hasnochildren(CurrentNode)){
                deletedself = 0;
            }
            else if(CurrentNode->val != 0){
                deletedself = 0;
            }
            else{
                CurrentNode = nullptr;
                deletedself = 1;
            }
        }
        else{
            deletedself = 0;
        }
        return deletedself;
    }*/
}


void Trie::remove(string key) { //any case of deletion should be done knowing that some of the letters of key can be used for other keys
    //For this reason letters of key should be removed one at a time from the bottom up
    //possible cases:
    //  Key may not be there in trie. Delete operation should not modify trie.
    //  Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie). Delete all the nodes.
    //  Key is prefix key of another long key in trie. Unmark the leaf node.
    //  Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.

    //TrieNode *curr = root; // start at the root of the tree


    //if ((root == nullptr)){
    //    return;
    //}

    leafnode = 0;

    this-> root = deleteHelper(key, this->root, key.length(), 0);
    tree_size = tree_size - totaltreesizedelete;
    map_size = map_size - 1;
    

    totaltreesizedelete = 0;

/*
    if (curr == nullptr)
    { // case 1, tree is empty
        return;
    }

    int len = key.length();
    //bool morechildren = 0;
    //for(int i = 0; i < len; i++){
      //  for(int j = 0; j < 26; j++){
        //    if()
       // }
    //}
    
    
    while (len > 0)
    {
        int i;
        for (i = 0; i < len; i++) // case 1, make sure key exists in tree
        { // loop through the key letter by letter. If a children node does not exist for a certain sequence of letters that means the key does not exist
            if (curr->children[key[i] - 'a'] == NULL)
            { // the [i] - 'a' chooses letters based on its index value.
                return; // 0 in this case signifies that the key does not exist in the tree because part of the key was not found while probing the tree
            }
            curr = curr->children[key[i] - 'a']; //continue down the path of the key's letters
        } // if the end of the loop is reached that means the key exists

        int numofchildren; //integrer value to hold number of children of bottom value of key

        for (int i = 0; i < 26 ; i++){
            if(curr->children[i] != NULL){
                numofchildren++;
            }
        }

        if(numofchildren < 1){
            tree_size--;
            free(curr);
            if(curr->val != 0){
                map_size--;
                curr->val = 0;
            }
        }else{
            if(curr->val != 0){
                map_size--;
                curr->val = 0;
            }
        }
        len--;
    }


*/
        
}