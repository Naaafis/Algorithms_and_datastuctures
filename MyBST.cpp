//
//  MyBST.cpp
//  bst_transform
//

#include "MyBST.h"
#include <queue>
#include <stack>

/**
 * Computes how to transform this MyBST into the target MyBST using transf.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */

//new funcitons

Node* MyBST:: find(int val){ // find equal key in another tree
    //stack<Node*> sta;a

    //could be accomplished with either a linked list of simplified using a queue
    
    queue<Node*> que;
    que.push( root);

    while (!que.empty())
    {
        Node *node1 = que.front();
        que.pop(); // this will eventually cause the while loop to end

        if (node1->key == val){
            return node1;
        }

        if (node1->left){
            que.push(node1->left);
        }

        if (node1->right){
            que.push(node1->right);
        }
    }

    return nullptr;
}

Node* MyBST::TraverseInOrder(int in)
{
    //stack<Node*> sta;
    
    //could be accomplished with either a linked list of simplified using a queue

    queue<Node *> que;
    que.push( root);
    int count = 0;


    while (!que.empty())
    {
        Node *node1 = que.front();
        que.pop();
        count++;
       
        if (count == in){
            return node1;
        }
      
        if (node1->left){
            que.push(node1->left);
        }
       
        if (node1->right){
            que.push(node1->right);
        }
    }

    return nullptr;
}

int MyBST::getLevel(Node *node, Node *ptr, int level){
    if (node == nullptr){
        return 0;
    }

    if (node->key == ptr->key){
        return level;
    }

    int height = getLevel(node->left, ptr, level + 1);

    if (height != 0){
        return height;
    }

    return getLevel(node->right, ptr, level + 1);
}

/*bool MyBST::isLeftChild(Node *parent, Node *child) // checks to see if second argument is the left child of first argument
{

    bool leftChild = false;

    if (parent && parent->left)
    {
        if (parent->left == child)
        {
            leftChild = true;
        }
    }

    return leftChild;
}

bool MyBST::isRightChild(Node *parent, Node *child) // checks to see if second argument is the right child of first argument
{

    bool rightChild = false;

    if (parent && parent->right)
    {
        if (parent->right == child)
        {
            rightChild = true;
        }
    }

    return rightChild;
}

bool MyBST::isParent(Node *parent, Node *child) // checks to see if parent is parent of child 
{
    return (isLeftChild(parent, child) || isRightChild(parent, child));
}*/

Node *MyBST::parent(Node *CurrentNode, int key)
{
    if ((CurrentNode->left == nullptr) && (CurrentNode->right == nullptr)){
        return nullptr;
    }

    if ((CurrentNode->left != nullptr && CurrentNode->left->key == key) || (CurrentNode->right != nullptr && CurrentNode->right->key == key)){
        return CurrentNode;
    }

    else if (CurrentNode->key > key){
        return parent(CurrentNode->left, key);
    }

    else{ 
        return parent(CurrentNode->right, key);
    }
}

/*

bool MyBST::isRoot(Node *rootNode)
{
    if (this->root != rootNode)
    {
        return false;
    }
    else
    {
        return true;
    }tu
}*/

vector<Rotation> MyBST::transform(MyBST target) {
    int i = 1;

    Node *thattree = target.root;
    vector<Rotation> transf;

    while (thattree){
        Node *thistree =  find(thattree->key);

        bool sameheight = 0;
        int height2 = target.getLevel(target.root, thattree, 1);

        while (!sameheight)
        {
            int height1 =  getLevel( root, thistree, 1);

            if (height1 == height2)
            {
                sameheight = 1;
            }

            else
            {
                Node *parent_thistree =  parent( root, thistree->key);

                if (thistree->key < parent_thistree->key)
                {
                    Rotation rot(parent_thistree->key, ZIG);
                    transf.push_back(rot);

                    if (parent_thistree->key ==  root->key)
                    {
                         root = rotateRight(parent_thistree);
                    }
                    else{
                        Node* grandParent_thistree =  parent( root, parent_thistree->key);
                        if (parent_thistree->key < grandParent_thistree->key)
                        {
                            grandParent_thistree->left =  rotateRight(parent_thistree);
                        }
                        else
                        {
                            grandParent_thistree->right =  rotateRight(parent_thistree);
                        }
                    }
                }
                else if (thistree->key > parent_thistree->key)
                {
                    Rotation rot(parent_thistree->key, ZAG);
                    transf.push_back(rot);
                    if (parent_thistree->key ==  root->key)
                    {
                         root = rotateLeft(parent_thistree);
                    }
                    else
                    {
                        Node *grandParent_thistree =  parent( root, parent_thistree->key);
                        if (parent_thistree->key < grandParent_thistree->key)
                        {
                            grandParent_thistree->left =  rotateLeft(parent_thistree);
                        }
                        else{
                            grandParent_thistree->right =  rotateLeft(parent_thistree);
                        }
                    }
                }
            }
        }
        i++;

        thattree = target.TraverseInOrder(i);
    }
    return transf;
}


Node* MyBST::rotateRight(Node* Q) // Zig rotation
{
    Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

/*
Node* MyBST::Zig(Node* Parent, Node* Q){ //ensure that parents receive the right children following roatation 
// rotation is based off of a parent 
    if(Parent->right == Q){
        Node *P = rotateRight(Q);
        Parent->right == P;
    }else if(Parent->left == Q){
        Node *P = rotateRight(Q);
        Parent->left == Q;
    }
}
*/

Node* MyBST::rotateLeft(Node* P) // Zag rotation
{
    Node* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    return Q;
}

/*
Node *MyBST::Zag(Node*Parent, Node *P){
    if (Parent->right == P){
        Node *Q = rotateLeft(P);
        Parent->right == Q;
    }
    else if (Parent->left == P){
        Node *Q = rotateLeft(P);
        Parent->left == P;
    }
}*/
