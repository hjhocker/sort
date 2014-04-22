/* program to check if a tree is height-balanced or not */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deque>
#define bool int
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int min(int, int);
int max(int, int);

void SortNodeParentandChild ( node *root ) {
  node *conductor=root;
  node *left=root->left;
  node *right=root->right;
  if (conductor->data < left->data) {
    int temp = conductor->data;
    conductor->data = left->data;
    left->data = temp;
  }

  if (conductor->data > right->data) {
    int temp = conductor->data;
    conductor->data = right->data;
    right->data = temp;
  }
  return;
}

void SortBinaryTree (node *node) { //combine a simple parent leaf sort with a breadth first search
  
  return;
}


int TreeDepth(node* pRoot)
{
    //std::cout << "Iteration" << std::endl;
    if(pRoot == NULL)
        return 0; //nLeft and nRight are initialized here
    int nLeft = TreeDepth(pRoot->left);
    int nRight = TreeDepth(pRoot->right);
    //std::cout << "nLeft " << nLeft << " nRight " << nRight << std::endl;
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

/* Returns the height of a binary tree */
int height(struct node* node);
 
/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct node *root)
{
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */ 
 
   /* If tree is empty then return true */
   if(root == NULL)
    return 1; 
 
   /* Get the height of left and right sub trees */
   lh = height(root->left);
   rh = height(root->right);
 
   if( abs(lh-rh) <= 1 && isBalanced(root->left) &&  isBalanced(root->right) )
     return 1;
 
   /* If we reach here then tree is not height-balanced */
   return 0;
}
 
/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
 
/* returns maximum of two integers */
int max(int a, int b) {
  return (a >= b) ? a : b;
}    

int min(int a, int b) {
  return (a<=b) ? a : b;
}
 
void BFS (node * root) {
  node *conductor = root;
  std::deque<node *> list;
  list.push_back(conductor);
  int level = 1;
  while ( list.size() > 0 ) {
    //std::cout << "Node found " << level << std::endl;
    node *node = list.front();
    list.pop_front();
    if (node->left)
      list.push_back(node->left);
    if (node->right)
      list.push_back(node->right);
    level++;
  }
  return;
}

void DFS (node * root) {

  return;
}


/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + max(height(node->left), height(node->right));
} 
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
 node* newNode(int data)
{
    //struct node* node = (struct node*) malloc(sizeof(struct node));
    struct node *node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(88);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(8);
 
    if(isBalanced(root))
      printf("Tree is balanced\n");
    else
      printf("Tree is not balanced\n");    
 
    int answer = TreeDepth(root);
    std::cout << "Tree Depth = " << answer << std::endl;

    std::cout << "Root " << root->data << std::endl;
    std::cout << "Left " << root->left->data << std::endl;
    std::cout << "Right " << root->right->data << std::endl;
    SortNodeParentandChild(root);
    std::cout << "Root " << root->data << std::endl;
    std::cout << "Left " << root->left->data << std::endl;
    std::cout << "Right " << root->right->data << std::endl;

    BFS(root);

    return 0;
}


