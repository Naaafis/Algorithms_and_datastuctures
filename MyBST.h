#ifndef __MYBST_H__
#define __MYBST_H__

#include <vector>
#include "BST.h"

class MyBST : public BST
{
    using BST::BST;
public:
    

    //new functions
    Node* find(int val);
    Node* TraverseInOrder(int index);

    int getLevel(Node *node, Node *ptr, int level);
    
    /*
    bool isParent(Node *parent, Node *child);
    bool isLeftChild(Node *parent, Node *child);
    bool isRightChild(Node *parent, Node *child);
    */

    Node *parent(Node *root, int value);

    /*
    bool isRoot(Node *rootNode);
    Node *Zig(Node* Parent, Node *Q);
    Node *Zag(Node* Parent, Node *Q);
    */

    vector<Rotation> transform(MyBST target);

    Node* rotateRight(Node* Q);
    Node* rotateLeft(Node* P);
};

#endif /* __MYBST_H__*/
