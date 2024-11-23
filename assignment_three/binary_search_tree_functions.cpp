#include <stdio.h>

class Node {
    public:
        int key;
        Node* parent;
        Node* left;
        Node* right;

        Node(int Value): key(Value),left(nullptr),right(nullptr),parent(nullptr) {} //Constructor
};

class BinarySearchTree {
    public:
        Node* Root;

        BinarySearchTree(Node* root): Root(root){} //Constructor
};

void InOrder_TreeWalk(Node *node)
{
    if (node != nullptr)
    {
        InOrder_TreeWalk(node->left); // Recursive walk call
        printf("%d\n", node->key);
        InOrder_TreeWalk(node->right); // Recursive walk call
    }
}

Node *Tree_Search(Node *node, int k)
{
    if (node == nullptr || k == node->key)
    { // If found return the node
        return node;
    }
    if (k < node->key)
    { // if smaller, keep searching the left subtree
       return Tree_Search(node->left, k);
    }
    else
        return Tree_Search(node->right, k); // if bigger, keep searching the right subtree
}

Node *Tree_Min(Node *node)
{
    while (node->left != nullptr)
    { // go left until you reach left most node
        node = node->left;
    }
    return node;
}

Node *Tree_Max(Node *node)
{
    while (node->right != nullptr)
    { // go right until you reach right most node
        node = node->right;
    }
    return node;
}

Node *Tree_Successor(Node *node)
{
    if (node->right != nullptr)
    { // if there is right child, get smallest of right subtree
        return Tree_Min(node->right);
    }
    else
    { // if there is no right child, get the lowest ancestor whose left child is an ancestor of node.
        Node *y = node->parent;
        while (y != nullptr && node == y->right)
        {
            node = y;
            y = y->parent;
        }
        return y;
    }
}

void Tree_Insert(BinarySearchTree *BinarySearchTree, Node *z)
{
    Node *x = BinarySearchTree->Root; // comparison will start with root
    Node *y = nullptr;                // will be the parent of the inserted node
    while (x != nullptr)
    { // traverse tree until finding a leaf where z can be placed
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    z->parent = y; // parent of Z is decided
    if (y == nullptr)
    { // if Y is null, that means tree is empty
        BinarySearchTree->Root = z;
    }
    else if (z->key < y->key)
    { // comparison of the key with parent, Z is placed accordingly
        y->left = z;
    }
    else
    { // comparison of the key with parent, Z is placed accordingly
        y->right = z;
    }
}

void Transplant(BinarySearchTree *BinarySearchTree, Node *u, Node *v)
{
    if (u->parent == nullptr)
    { // means that U is root, then change root of tree with V
        BinarySearchTree->Root = v;
    }
    else if (u == u->parent->left)
    {                        // if U is left child of its parent
        u->parent->left = v; // U's parent now points to v instead of U
    }
    else
    {
        u->parent->right = v; // same if it's the right child
    }
    if (v != nullptr)
    { // make V's parent U's parent
        v->parent = u->parent;
    }
}

void Tree_Delete(BinarySearchTree *BinarySearchTree, Node *z)
{
    if (z->left == nullptr)
    {
        Transplant(BinarySearchTree, z, z->right); // Transplant Z.right subtree into Z if Z has no left child
    }
    else if (z->right == nullptr)
    {
        Transplant(BinarySearchTree, z, z->left); // Same with left subtree if Z has no right child
    }
    else
    {
        Node *y = Tree_Min(z->right); // Y is Z's successor
        if (y != z->right)            // If Y is farther down the tree
        {
            Transplant(BinarySearchTree, y, y->right); // Replace Y by its child
            y->right = z->right;                       // assign Z's right child as Y's right child
            y->right->parent = y;                      // assign Z's right child's parent as Y
        }
        Transplant(BinarySearchTree, z, y); // Replace Z with its successor
        y->left = z->left;                  // assign Z's left child as Y's left child
        y->left->parent = y;
    }
}

int main(){
Node nodes[8]={Node(252), Node(401), Node(398), Node(2), Node(330), Node(344), Node(397), Node(363)}; //Initializing Nodes
BinarySearchTree BST(nullptr); //Initializng BST
BinarySearchTree* BST_PTR=&BST; //Pointer to BST

for(Node &n: nodes){ //Inserting nodes to BST
    Tree_Insert(BST_PTR, &n);
    // int r=BST_PTR->Root->key;
    // printf("%d\n",r); //Confirming root is stable
}

printf("In Order Tree Walk After Insertion:\n");
InOrder_TreeWalk(BST_PTR->Root);

Node* found_node_ptr=Tree_Search(BST_PTR->Root, 330);

printf("Found node: %d\n",found_node_ptr->key);

Node* successor_node_ptr=Tree_Successor(Tree_Search(BST_PTR->Root,363));

printf("Successor node %d\n",successor_node_ptr->key);

Node* min_node_ptr=Tree_Min(BST_PTR->Root);

printf("Minimum Node: %d\n",min_node_ptr->key);

Tree_Delete(BST_PTR, Tree_Search(BST_PTR->Root,398));

printf("In Order Tree Walk After Deletion of 398:\n");

InOrder_TreeWalk(BST_PTR->Root);
}
